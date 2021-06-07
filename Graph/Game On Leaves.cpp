#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define si set<int>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1363/problem/C
const int N = 1000;
vi g[N+1];
int level[N+1], parent[N+1], deg[N+1];

struct Leaf {
    int node, depth;
    Leaf(int _n, int _d) {
        node = _n; depth = _d;
    }
    bool operator < (const Leaf &b) const {
        return b.depth > depth;
    }
};

void dfs(int u, int p) {
    level[u] = level[p]+1;
    parent[u] = p;
    for (int v: g[u]) 
        if (v != p) dfs(v, u);
}

void solve() {
    int n, x, u, v;
    cin >> n >> x;
    for (int i = 0; i <= n; i++) g[i].clear(), level[i] = 0, parent[i] = 0, deg[i] = 0;
    for (int i = 1; i <= n-1; i++) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    level[0] = -1;
    dfs(x, 0);
    bool winner[] = {true, true};
    int cnt = 0;
    priority_queue<Leaf> pq;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            pq.push(Leaf(i, level[i]));
            if (i == x) winner[1] = false;
        }
        deg[i] = g[i].size();
    }
    
    while ((winner[0]) && (winner[1]) && (!pq.empty())) {
        int curr = pq.top().node; pq.pop();
        int p = parent[curr];
        deg[curr]--; deg[p]--;
        if (deg[p] == 1) {
            pq.push(Leaf(p, level[p]));
            if (p == x) winner[cnt % 2] = false;
        }
        cnt++;
    }
    if (winner[0]) cout << "Ayush\n";
    else cout << "Ashish\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
