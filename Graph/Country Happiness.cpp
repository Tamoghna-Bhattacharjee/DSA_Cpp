#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back   

// https://codeforces.com/contest/1388/problem/C

const int N = 1e5;
vi g[N+1];
int p[N+1], h[N+1], tp[N+1], gm[N+1];
bool ok;

void dfs(int u, int par) {
    tp[u] = p[u];
    int sum = 0;
    for (int v: g[u]) {
        if (v != par) {
            dfs(v, u);
            tp[u] += tp[v];
            sum += gm[v];
        }
    }
    if ((h[u] + tp[u]) % 2 == 0) gm[u] = (h[u] + tp[u]) / 2;
    else ok = false;
    if (gm[u] < 0 || gm[u] > tp[u]) ok = false;
    if (sum > gm[u]) ok = false;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    ok = true;
    for (int i = 0; i <= n; i++) g[i].clear(), tp[i] = 0, gm[i] = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < n-1; i++) cin >> x >> y, g[x].pb(y), g[y].pb(x);
    dfs(1, 0);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}