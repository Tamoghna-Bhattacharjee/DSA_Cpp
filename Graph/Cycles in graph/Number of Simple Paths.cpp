#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e9-1, MOD = 998244353;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1454/problem/E

set<int> g[2*N+1];
vector<int> cycle;
int par[2*N+1], cnt[2*N+1], visit[2*N + 1], deg[2*N+1];

void dfs(int u, int p) {
    if (visit[u] == 2) return;
    if (visit[u] == 1) {
        int cur = p;
        cycle.pb(cur);
        while (cur != u) {
            cur = par[cur];
            cycle.pb(cur);
        }
        return;
    }
    visit[u] = 1;
    par[u] = p;
    for (int v: g[u]) 
        if (v != p) dfs(v, u);
    visit[u] = 2;
}

void bfs_OnLeaves(int n) {
    memset(visit, 0, 4*(n+1));
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visit[u] = 1;
        for (int v: g[u]) {
            if (visit[v] == 0) {
                cnt[v] += cnt[u];
                deg[u]--; deg[v]--;
                if (deg[v] == 1) q.push(v);
            }
        }
    }
}

void solve () {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) g[i].clear(), par[i] = 0, visit[i] = 0, cnt[i] = 1, deg[i] = 0;
    cycle.clear();

    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++; deg[v]++;
    }
    dfs(1,0);
    bfs_OnLeaves(n);
    lli ans = 0;
    for (int i: cycle) {
        ans += 1LL * cnt[i] * (cnt[i] - 1)/2LL;
        ans += 1LL * cnt[i] * (n - cnt[i]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    while (t--) solve();
}