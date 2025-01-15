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

// https://leetcode.com/problems/valid-arrangement-of-pairs/description

unordered_map<int, vector<int>> g;
unordered_map<int, int> indeg, outdeg;
vector<int> res;

void solve() {
    int m; cin >> m; // num of edges of the graph
    vector<vi> a(m); for (auto &i: a) cin >> i[0] >> i[1];

    for (auto &i: a) {
        int u = i[0], v = i[1];
        g[u].pb(v);
        indeg[v]++;
        outdeg[u]++;
    }
    
    int root = a[0][0];
    for (auto &i: g) {
        if (outdeg[i.first] == indeg[i.first] + 1) root = i.first;
    }
    
    stack<int> s; s.push(root);
    while (!s.empty()) {
        int u = s.top();
        if (outdeg[u] > 0) {
            s.push(g[u][outdeg[u]-1]);
            outdeg[u]--;
        } else {
            s.pop();
            res.pb(u);
        }
    }

    vector<vi> ans;
    reverse(all(res));
    for (int i = 0; i < res.size()-1; i++) {
        ans.pb({res[i], res[i+1]});
    }
    for (auto &i: ans) debug(i);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}