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

const lli INF = 1e18, MOD = 1e9+7;
const int N = 7e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1594/problem/E2

map<string, lli> c;
map<lli, vlli> adj;
map<lli, lli> col;
map<lli, vlli> dp;
set<lli> eff;

bool dfs(lli u) {
    if (eff.find(u) == eff.end()) return false;
    bool L = dfs(2*u), R = dfs(2*u+1);

    vlli arr;
    if (col.find(u) != col.end()) arr = {col[u]};
    else arr = {0,1,2,3,4,5};

    dp[u] = vlli(6);
    if (L && R) {
        for (lli i: arr) {
            for (lli j: adj[i]) {
                for (lli k: adj[i]) {
                    dp[u][i] = (dp[u][i] + dp[2*u][j] * dp[2*u+1][k] % MOD) % MOD;
                }
            }
        }
    } else if (L) {
        for (lli i: arr) {
            for (lli j: adj[i]) {
                dp[u][i] = (dp[u][i] + dp[2*u][j]) % MOD;
            }
        }
    } else if (R) {
        for (lli i: arr) {
            for (lli j: adj[i]) {
                dp[u][i] = (dp[u][i] + dp[2*u + 1][j]) % MOD;
            }
        }
    } else dp[u][col[u]] = 1;
    return true;
}

lli power(lli a, lli n) {
    lli res = 1;
    while (n > 0) {
        if (n%2) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res % MOD;
}

void solve() {
    c["white"] = 0; c["blue"] = 1;
    c["red"] = 2; c["yellow"] = 3;
    c["green"] = 4; c["orange"] = 5;
    adj[0] = {1,2,4,5}; adj[1] = {0,2,3,5};
    adj[2] = {0,1,3,4}; adj[3] = {1,2,4,5};
    adj[4] = {0,2,3,5}; adj[5] = {0,1,3,4};

    lli k, n; cin >> k >> n;
    for (int i = 0; i < n; i++) {
        lli x; string s; cin >> x >> s;
        col[x] = c[s];
        while (x > 0 && eff.find(x) == eff.end()) {
            eff.insert(x);
            x /= 2;
        } 
    }
    dfs(1);
    lli ans = 0;
    for (lli i: dp[1]) ans = (ans + i) % MOD;
    lli total = (1LL << k) - 1LL;
    ans = ans * power(4,total - ((lli) eff.size())) % MOD;
    cout << ans << endl;
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