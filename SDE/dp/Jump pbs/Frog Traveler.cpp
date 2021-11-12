#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

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

const lli INF = 1e18, MOD = 998244353;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1602/problem/D

void solve() {
    int n; cin >> n;
    vi a(n+1), b(n+1), dp(n+1, INT_MAX);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    set<int> unvisit; 
    for (int i = 1; i <= n; i++) unvisit.insert(i);
    queue<pair<int, int>> q;
    map<int, int> par;
    dp[n] = 0; q.push({n,n}); par[n] = -1; unvisit.erase(n);

    while (!q.empty()) {
        int landed = q.front().first;
        int cur = q.front().second;
        q.pop();
        if (cur - a[cur] <= 0) {
            if (dp[cur] + 1 < dp[0]) {
                dp[0] = 1 + dp[cur];
                par[0] = landed;
            }
        }
        auto it = unvisit.lower_bound(cur - a[cur]);
        while (it != unvisit.end() && *it < cur) {
            int to = *it + b[*it];
            if (dp[cur]+1 < dp[to]) {
                dp[to] = 1 + dp[cur];
                par[*it] = landed;
                q.push({*it, to});
            }
            unvisit.erase(it);
            it = unvisit.lower_bound(cur - a[cur]);
        }
    } 
    if (dp[0] == INT_MAX) {
        cout << -1 << endl; return;
    }
    cout << dp[0] << endl;
    int cur = 0;
    vi res;
    while (cur != -1) {
        res.pb(cur);
        cur = par[cur];
    }
    res.pop_back();
    reverse(res.begin(), res.end());
    debug(res);
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}