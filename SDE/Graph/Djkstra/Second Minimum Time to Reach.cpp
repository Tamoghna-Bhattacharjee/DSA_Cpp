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

// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

void solve() {
    int n, m; cin >> n >> m;
    int time, change; cin >> time >> change;
    vector<vi> g(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    vector<vi> dp(2, vi(n+1, INT_MAX)); dp[0][1] = 0;
    vi freq(n+1); freq[1] = 1;
    priority_queue<pair<int, int>> pq; pq.push({0,1});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int t = -cur.first, u = cur.second;
        
        if ((t/change) % 2) {
            t = (t/change + 1) * change + time;
        } else t += time;

        for (int v: g[u]) {
            if (freq[v] == 2) continue;
            if (t < dp[0][v]) {
                dp[1][v] = dp[0][v];
                dp[0][v] = t;
                pq.push({-t, v});
                freq[v]++;
            } else if (t < dp[1][v] && dp[0][v] != t) {
                dp[1][v] = t;
                pq.push({-t, v});
                freq[v]++;
            }
        }
    }
    cout << dp[1][n] << endl;
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