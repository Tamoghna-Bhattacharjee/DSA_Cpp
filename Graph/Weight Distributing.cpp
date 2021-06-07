#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1343/problem/E

const int maxN = 200005;
vi g[maxN];
lli arr[maxN];

void bfs(int s, int *d) {
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d[to] == INT_MAX) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
}

int main() {
    int T,n,m,a,b,c,u,v;
    cin >> T;
    while (T--) {
        cin >> n >> m >> a >> b >> c;
        int da[n+1], db[n+1], dc[n+1];
        for (int i = 0; i <= n; i++) g[i].clear(), da[i] = db[i] = dc[i] = INT_MAX;
        for (int i = 1; i <= m; i++) cin >> arr[i];
        for (int i = 1; i <= m; i++) cin >> u >> v, g[u].pb(v), g[v].pb(u);
        
        sort(arr, arr+m+1);
        for (int i = 1; i <= m; i++) arr[i] += arr[i-1];

        da[a] = db[b] = dc[c] = 0;
        bfs(a, da);
        bfs(b, db);
        bfs(c, dc);

        lli ans = 1e18;
        for (int i = 1; i <= n; i++) {
            if (da[i] + db[i] + dc[i] > m) continue;
            ans = min(ans, arr[db[i]] + arr[da[i] + db[i] + dc[i]]);
        }
        cout << ans << endl;
    }
}