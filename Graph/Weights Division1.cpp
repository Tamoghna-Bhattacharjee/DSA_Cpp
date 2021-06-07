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

// https://codeforces.com/contest/1399/problem/E1

struct edgeContri {
    lli w, diff;
    int f;
    edgeContri(){};
    edgeContri(long _w, int _f) {
        w = _w; f = _f; 
        diff = w*f*1LL - (w/2)*f*1LL;
    }
    bool operator < (const edgeContri &b) const {
        return diff < b.diff;
    }
};

const int N = 1e5;
vector<pair<int, lli>> g[N+1];
int leaves[N+1];
lli sum;

void dfs1(int u, int p) {
    for (auto to: g[u]) {
        if (to.first != p) {
            dfs1(to.first, u);
            leaves[u] += leaves[to.first];
        }
    }
    if (g[u].size() == 1 && p != -1) leaves[u] = 1;
}

void dfs2(int u, int p, priority_queue<edgeContri> &pq) {
    for (auto to: g[u]) {
        if (to.first != p) {
            pq.push(edgeContri(to.second, leaves[to.first]));
            sum += to.second * leaves[to.first] * 1LL;
            dfs2(to.first, u, pq);
        }
    }
}

void solve() {
    int n, u, v; 
    lli s, w; cin >> n >> s;
    sum = 0;
    for (int i = 0; i <= n; i++) g[i].clear(), leaves[i] = 0;
    for (int i = 0; i < n-1; i++) cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    
    priority_queue<edgeContri> pq;
    dfs1(1, -1);
    dfs2(1, -1, pq);
    
    int cnt = 0;
    while (sum > s) {
        edgeContri e = pq.top(); pq.pop();
        sum = sum - e.w * e.f * 1LL + (e.w/2) * e.f * 1LL;
        cnt++;
        pq.push(edgeContri(e.w/2, e.f));
    }   
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t; 
    while (t--) solve();
}