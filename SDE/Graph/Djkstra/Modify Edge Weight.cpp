#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 

template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);


// https://leetcode.com/problems/modify-graph-edge-weights/

// n <= 100                            n -> #nodes
// n-1 <= m <= n*(n-1)/2               m -> #edges

vector<pair<int, int>> g[100];

lli djkstra(int source, int dest, int n) {
    vector<lli> dist(n, INF);
    priority_queue<pair<lli, int>> pq;
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        lli d = -cur.first, u = cur.second;
        for (auto to: g[u]) {
            lli v = to.first, w = to.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({-dist[v], v});
            }
        }
    }
    return dist[dest];
}
vector<vi> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, 
                              int dest, int target) {
    for (auto &e: edges) {
        if (e[2] != -1) {
            g[e[0]].pb({e[1], e[2]});
            g[e[1]].pb({e[0], e[2]});
        }
    }
    lli d = djkstra(source, dest, n);
    if (d < target) return {};
    bool ok = d == target;
    for (int i = 0; i < edges.size() && !ok; i++) {
        auto &e = edges[i];
        if (e[2] == -1) {
            e[2] = 1;
            g[e[0]].pb({e[1], e[2]});
            g[e[1]].pb({e[0], e[2]});
            d = djkstra(source, dest, n);
            if (d <= target) {
                e[2] += target-d;
                ok = true;
            }
        }
    }
    for (auto &i: edges) {
        if (i[2] == -1) i[2] = 2e9;
    }
    if (ok) return edges;
    return {};
}

void solve() {
    int n, m; cin >> n >> m; // n -> #nodes, m-> #edges
    vector<vi> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.pb({u, v, w});
    }
    int source, dest, target; cin >> source >> dest >> target;
    auto ans = modifiedGraphEdges(n, edges, source, dest, target);

    for (auto &i: ans) debug(i);
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}