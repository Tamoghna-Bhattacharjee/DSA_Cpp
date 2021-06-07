#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18-1, MOD = 998244353;
const int N = 1000; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1433/problem/G

vector<pair<int, int>> g[N+1], nodes(N+1), edges(N+1);
vi w(N+1);
int d[N+1][N+1];
int n, m, k;

void djkstras(int s) {
    for (int i = 0; i <= n; i++) d[s][i] = INT_MAX;
    d[s][s] = 0;
    priority_queue<pair<int, int>> pq; pq.push({0, s});
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int dist = -cur.first, u = cur.second;
        for (auto to: g[u]) {
            int v = to.first, ind = to.second;
            if (dist + w[ind] < d[s][v]) {
                d[s][v] = dist + w[ind];
                pq.push({-d[s][v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v >> w[i];
        g[u].pb({v, i});
        g[v].pb({u, i});
        edges[i] = {u, v};
    }
    for (int i = 1; i <= n; i++) djkstras(i);
    
    for (int i = 1; i <= k; i++) {
        int a, b; cin >> a >> b;
        nodes[i] = {a, b};
    }
    int ans = INT_MAX;
    for (int i = 1; i <= m; i++) {
        int sum = 0; 
        int x = edges[i].first, y = edges[i].second;
        for (int j = 1; j <= k; j++) {
            int a = nodes[j].first, b = nodes[j].second;
            sum += min(d[a][b], min(d[a][x] + d[y][b], d[a][y] + d[x][b]));
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}