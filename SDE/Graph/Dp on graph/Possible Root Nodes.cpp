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

// https://leetcode.com/problems/count-number-of-possible-root-nodes/description/

// n nodes from 0 to n-1;
// m -> number of guesses
// s -> guesses

// Input: edges = [[0,1],[1,2],[1,3],[4,2]], 
// guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
// ans = 3


vi g[N];
set<pair<int, int>> s;
map<pair<int, int>, int> dp;

int dfs(int u, int p) {
    pair<int, int> x = {p, u};
    if (dp.find(x) != dp.end()) return dp[x];
    dp[x] = 0;
    if (s.find(x) != s.end()) dp[x]++;
    for (int v: g[u]) {
        if (v != p) dp[x] += dfs(v, u);
    }
    return dp[x];
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    s.clear(); dp.clear();
    for (int i = 0; i <= n-1; i++) g[i].clear();
    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        s.insert({u, v}); 
    }
    int ans = 0;
    for (int i = 0; i <= n-1; i++) {
        if (dfs(i, -1) >= k) ans++;
    }
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
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}