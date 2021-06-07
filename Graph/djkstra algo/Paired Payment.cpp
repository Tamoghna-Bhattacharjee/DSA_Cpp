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
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1486/problem/E

vpii g[N+5];
int n, m, dist[N+5][51];

void djkstra() {
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= 51; j++) dist[i][j] = INT_MAX;
    priority_queue<pair<int, pair<int, int>>> pq; // {-dist, {vtx, last_w}}
    pq.push({0, {1, 0}}); 
    dist[1][0] = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int d = -cur.first, u = cur.second.first, lw = cur.second.second;
        for (auto to: g[u]) {
            int v = to.first, nw = to.second;
            int newDist = d;
            if (lw) newDist += (lw + nw) * (lw + nw);
            if (lw) nw = 0;
            if (newDist < dist[v][nw]) {
                dist[v][nw] = newDist;
                pq.push({-dist[v][nw], {v, nw}});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (dist[i][0] != INT_MAX? dist[i][0]: -1) << " ";
    }
}

void solve() {  
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    djkstra();
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) solve();
}