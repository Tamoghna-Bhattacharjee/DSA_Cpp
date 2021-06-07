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

// https://codeforces.com/contest/1406/problem/C

vi g[N+1], centroids;
int subTree[N+1], n;

void dfs(int u, int p) {
    subTree[u] = 1;
    bool isCentroid = true;
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
            subTree[u] += subTree[v];
            if (subTree[v] > n/2) isCentroid = false;
        }
    }
    if (n-subTree[u] > n/2) isCentroid = false;
    if (isCentroid) centroids.pb(u);
}

void solve() {
    int x, y; cin >> n;
    centroids.clear();
    for (int i = 0; i <= n; i++) g[i].clear(), subTree[i] = 0;
    for (int i = 0; i < n-1; i++) cin >> x >> y, g[x].pb(y), g[y].pb(x);
    dfs(1,0);
    x = centroids[0];
    if ((int) centroids.size() == 1) {
        cout << x << " " << g[x][0] << endl;
        cout << x << " " << g[x][0] << endl;
    } else {
        y = centroids[1];
        int chY = -1;
        for (int i: g[y]) {
            if (i != x) {
                chY = i; break;
            }
        }
        cout << y << " " << chY << endl;
        cout << x << " " << chY << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;  cin >> t;
    while (t--) solve();
}