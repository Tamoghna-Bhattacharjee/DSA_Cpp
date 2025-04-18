#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back
#define all(__x) __x.begin(),__x.end()

template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

vi dsu;

int findNode(int x) {
    if (dsu[x] < 0) return x;
    return dsu[x] = findNode(dsu[x]);
}

bool unionNode(int a, int b) {
    a = findNode(a); b = findNode(b);
    if (a == b) return false;
    if (dsu[a] <= dsu[b]) swap(a, b);
    dsu[b] += dsu[a];
    dsu[a] = b;
    return true;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<vi> edges(m, vi(3));
    for (auto &i: edges) {
        for (auto &j: i) cin >> j; // u, v, w
    }
    vector<vi> qry(q, vi(3));
    for (auto &i: qry) {
        for (auto &j: i) cin >> j; // pi, qi, limit
    }
    
    vi idx;
    for (int i = 0; i < m; i++) idx.pb(i);

    sort(all(idx), [&](int &a, int &b) {
        return qry[a][2] < qry[b][2]; // sort based on limit
    });

    sort(all(edges), [](vi &a, vi &b) {
        return a[2] < b[2]; // sort based on weight
    });
    
    dsu = vi(n, -1);
    vector<bool> ans(m);
    
    int j = 0;
    for (int i: idx) {
        while (j < edges.size() && edges[j][2] < qry[i][2]) {
            int u = edges[j][0], v = edges[j][1];
            unionNode(u, v);
            j++;
        }
        int p = qry[i][0], q = qry[i][1];
        ans[i] = findNode(p) == findNode(q);
    }

    debug(ans);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}