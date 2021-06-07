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
const lli INF = 1e18;

// https://codeforces.com/contest/1388/problem/D

const int N = 1e5;
vi g[2*N + 1], res[2];
bool visit[2*N+1];
lli a[2*N+1], b[2*N+1], n;
lli ans = 0;

void dfs(int u) {
    visit[u] = true;
    for (int v: g[u]) {
        if (!visit[v]) {
            dfs(v);
        }
    }
    ans += (ll) a[u];
    if (b[u] != -1 && a[u] > 0) a[b[u]] += a[u];
    if (a[u] >= 0) res[1].pb(u);
    else res[0].pb(u);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) g[b[i]].pb(i);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) dfs(i);
    }
    cout << ans << endl;
    for (int i: res[1]) cout << i << " ";
    for (int i = res[0].size()-1; i >= 0; i--) cout << res[0][i] << " ";
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    while (t--) solve();
}