#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back   
const lli INF = 1e18-1, MOD = 1000000007;
const int N = 1e5;

// https://codeforces.com/contest/1405/problem/D

vi g[N+1];
int dist1[N+1], dist2[N+1], mx, node;

void dfs(int u, int p, int dist[]) {
   dist[u] = dist[p] + 1;
   if (dist[u] > mx) mx = dist[u], node = u;
   for (int v: g[u]) {
      if (v != p) dfs(v, u, dist);
   }
}

void solve() {
   int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
   for (int i = 0; i <= n; i++) g[i].clear(), dist1[i] = dist2[i] = INT_MAX;
   for (int i = 0; i < n-1; i++) {
      int u, v; cin >> u >> v;
      g[u].pb(v); g[v].pb(u);
   }
   dist1[0] = dist2[0] = -1;
   mx = 0; node = -1;
   dfs(a, 0, dist1);
   mx = 0;
   dfs(node, 0, dist2);
   int dia = mx;
   if (dist1[b] <= da || 2*da >= dia || db <= 2*da) cout << "Alice\n";
   else cout << "Bob\n"; 
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; cin >> t;
   while (t--) solve();
}