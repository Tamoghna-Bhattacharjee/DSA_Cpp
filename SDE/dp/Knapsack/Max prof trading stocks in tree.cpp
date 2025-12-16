#include <bits/stdc++.h>
#include <queue>
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
const int N = 160;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts
// dp[u][parent bought][budget] => max profit on subtree of u for given budget 
//                                 based on parent bought stocks or not
// For each u -> v we would already know dp values of v for all state and budget
// Use 2 knapsacks:
//             1. Take v or not take v
//             2. For u, buy stock or don't buy 

int n, tot;
vi g[N+1];
lli dp[N+1][2][200];

void dfs(int u, vi &pre, vi &fut) {
    int buy = pre[u], dbuy = pre[u]/2;

    vector<vlli> kdp(2, vlli(tot+1, INT_MIN));
    kdp[0][0] = kdp[1][0] = 0;

    for (int v: g[u]) {
        dfs(v, pre, fut);
        vector<vlli> nkdp(2, vlli(tot+1));
        for (int i = 0; i <= tot; i++) {
            // not taking v
            nkdp[0][i] = kdp[0][i];
            nkdp[1][i] = kdp[1][i];
            for (int j = 0; j <= i; j++) {
                // taking v
                nkdp[0][i] = max(nkdp[0][i], kdp[0][i-j] + dp[v][0][j]);
                nkdp[1][i] = max(nkdp[1][i], kdp[1][i-j] + dp[v][1][j]);
            }
        }
        kdp = nkdp;
    }

    for (int i = 0; i <= tot; i++) {
        dp[u][0][i] = dp[u][1][i] = kdp[0][i]; // u not buying
        if (i - buy >= 0) {
            dp[u][0][i] = max(dp[u][0][i], kdp[1][i-buy] + fut[u] - buy);
        }
        if (i - dbuy >= 0) {
            dp[u][1][i] = max(dp[u][1][i], kdp[1][i-dbuy] + fut[u] - dbuy);
        }
    }
}

void solve() {
    cin >> n >> tot;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        for (int j = 0; j <= tot; j++) {
            dp[i][0][j] = dp[i][1][j] = 0;
        }
    }

    vi pre(n), fut(n);
    for (auto &i: pre) cin >> i;
    for (auto &i: fut) cin >> i;

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; // 0-based
        g[u].pb(v);
    }

    dfs(0, pre, fut);
    lli ans = 0;
    for (int i = 0; i <= tot; i++) {
        ans = max(ans, dp[0][0][i]);
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