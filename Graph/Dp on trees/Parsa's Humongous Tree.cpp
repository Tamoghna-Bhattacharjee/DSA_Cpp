#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1529/problem/C

lli n;
lli range[N+1][2];
vi g[N+1];
lli dp[N+1][2];

lli dfs(int u, int p, int flag) {
    if (dp[u][flag] != -1) return dp[u][flag];
    lli ans = 0;
    for (int v: g[u]) {
        if (v != p) {
            lli x = abs(range[u][flag] - range[v][0]) + dfs(v,u,0);
            lli y = abs(range[u][flag] - range[v][1]) + dfs(v,u,1);
            ans += max(x,y);
        }
    }
    return dp[u][flag] = ans;
}   

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) g[i].clear(), dp[i][0] = dp[i][1] = -1;
    for (int i = 1; i <= n; i++) cin >> range[i][0] >> range[i][1];
    
    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout << max(dfs(1,-1,0), dfs(1,-1,1)) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}