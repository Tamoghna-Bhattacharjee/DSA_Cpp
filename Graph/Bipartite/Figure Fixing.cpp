#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};  

// https://codeforces.com/contest/1537/problem/F

vi g[N+1];
bool visit[N+1], color[N+1];
lli a[N+1];

bool dfs(int u, int p, int c) {
    visit[u] = true;
    color[u] = c;
    bool ok = true;
    for (int v: g[u]) {
        if (v == p) continue;
        else if (!visit[v]) ok = ok && dfs(v, u, 1^c);
        else ok = ok && color[v] != color[u];
    }
    return ok;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++) g[i].clear(), visit[i] = color[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    lli sum = 0;
    for (int i = 1; i <= n; i++) {
        lli target; cin >> target;
        a[i] = target - a[i];
        sum += a[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (abs(sum % 2) == 1) {
        cout << YN[0] << endl; 
        return;
    }

    bool isBipartite = dfs(1,-1,1);
    if (!isBipartite) cout << YN[1] << endl;
    else {
        lli s[] = {0,0};
        for (int i = 1; i <= n; i++) {
            s[color[i]] += a[i];
        }
        cout << YN[s[0] == s[1]] << endl;
    }
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