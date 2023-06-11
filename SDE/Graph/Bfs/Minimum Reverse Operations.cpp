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

// https://leetcode.com/problems/minimum-reverse-operations/description/

// Calculation of starting and ending one is the hard part

vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    vi dist(n,-1); dist[p] = 0; 
    set<int> s[2];
    for (int i = 0; i < n; i++) s[i%2].insert(i);
    for (int i: banned) s[i%2].erase(i);
    queue<int> q; q.push(p);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        s[u%2].erase(u);
        int L = max(0, u-k+1), R = min(n-1, u+k-1);
        int startOne = (L+k-1) - (u-L);
        int endOne = R-(u-(R-k+1));
        int ind = startOne % 2;
        vector<int> e;
        for (auto it = s[ind].lower_bound(startOne); it != s[ind].end(); it++) {
            if (*it > endOne) break;
            dist[*it] = dist[u] + 1;
            q.push(*it);
            e.pb(*it);
        }
        for (int i: e) s[ind].erase(i);
    }
    return dist;
}

void solve() {
    int n, p, m; cin >> n >> p >> m;
    vi banned(m); for (auto &i: banned) cin >> i;
    int k; cin >> k;
    cout << minReverseOperations(n, p, banned, k) << endl;
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