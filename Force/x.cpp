/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long int 
const lli INF = 1e18;

int main() {
	int n, m; cin >> n >> m;
    vector<pair<lli, lli>> g[n+1];
	for (int i = 0; i < m; i++) {
		lli u, v, c; cin >> u >> v >> c;
		g[u].pb({v,c}); g[v].pb({u,c});
	}	

	priority_queue<pair<lli, lli>> pq; // c,node
	vector<lli> dist(n+1, INF);
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		lli d = -cur.first, u = cur.second;
		for (auto to: g[u]) {
			lli v = to.first, cost = to.second;
			lli mx = max(0LL, cost - d) + d;
			if (mx < dist[v]) {
				dist[v] = mx;
				pq.push({-dist[v], v});
			}
		}
	}
	if (dist[n] == INF) cout << "NOT POSSIBLE\n";
    else cout << dist[n] << endl;
    return 0;
}
