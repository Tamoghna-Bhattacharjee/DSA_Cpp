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

// https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

vi g[12];

void solve() {
    int n, m; cin >> n >> m; // n: nodes, m:edges
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        g[u].pb(v); g[v].pb(u);
    }

    int dp[n][1<<n]; memset(dp, -1, sizeof dp);
    int M = (1<<n)-1;
    queue<pair<int, int>> q; // {mask, node}
    for (int i = 0; i < n; i++) {
        q.push({1<<i, i}); dp[i][1<<i] = 0;
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int mask = cur.first, u = cur.second;
        for (int v: g[u]) {
            int newMask = mask | (1 << v);
            if (dp[v][newMask] == -1) {
                dp[v][newMask] = dp[u][mask] + 1;
                q.push({newMask, v});
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) ans = min(ans, dp[i][M]);
    cout << ans << endl;
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