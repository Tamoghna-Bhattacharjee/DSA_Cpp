#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back  
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}
void debug(int _a) {cout << _a << " ";}

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 1e5;  

// https://codeforces.com/contest/1422/problem/D

int dist[N+1];
vi g[N+1];

bool cmp(vector<int> &p1, vector<int> &p2) {
    if (p1[0] != p2[0]) return p1[0] < p2[0];
    else return p1[1] < p2[1];
}

void bfs(int sx, int sy, vpii &p) {
    dist[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int d = -cur.first, u = cur.second;
        for (int v: g[u]) {
            if (d + min(abs(p[u].first - p[v].first), abs(p[u].second - p[v].second)) < dist[v]) {
                dist[v] = d + min(abs(p[u].first - p[v].first), abs(p[u].second - p[v].second));
                pq.push({-dist[v], v}); 
            }
        }
    } 
}

void solve() {
    int n, m; cin >> n >> m;
    int sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;
    vpii p(m+1);
    p[0] = {sx, sy};
    vector<vi> px, py;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        p[i] = {x, y};
        px.pb({x, y, i});
        py.pb({y, x, i});
    }
    sort(px.begin(), px.end()); 
    sort(py.begin(), py.end());
    for (int i = 0; i < m-1; i++) { 
        g[px[i][2]].pb(px[i+1][2]), g[px[i+1][2]].pb(px[i][2]);
        g[py[i][2]].pb(py[i+1][2]), g[py[i+1][2]].pb(py[i][2]);
    }
    for (int i = 1; i <= m; i++) g[0].pb(i), g[i].pb(0), dist[i] = INT_MAX;

    bfs(sx, sy, p);
    int ans = abs(sx-fx) + abs(sy-fy);
    for (int i = 1; i <= m; i++) ans = min(ans, dist[i] + abs(p[i].first - fx) + abs(p[i].second - fy));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}