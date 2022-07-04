#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

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

// https://codeforces.com/contest/1679/problem/D

lli n, m, k;
lli a[N+1];
vi g[N+1], g2[N+1];

void dfs(int u, vector<int> &visit, bool &isCycle) {
    visit[u] = 1;
    for (int v: g2[u]) {
        if (!visit[v]) dfs(v, visit, isCycle);
        else if (visit[v] == 1) isCycle = true;
    }
    visit[u] = 2;
}

bool check(lli x) {
    for (int i = 0; i <= n; i++) g2[i].clear();
    vlli indeg(n+1);
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            for (int v: g[i]) {
                if (a[v] <= x) g2[i].pb(v), indeg[v]++;
            }
        }
    }
    vector<int> visit(n+1);
    bool isCycle = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x && !visit[i]) dfs(i, visit, isCycle);
    }
    if (isCycle) return true;
    queue<int> bfs;
    vlli dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x && indeg[i] == 0) bfs.push(i);
    }
    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        for (int v: g2[u]) {
            indeg[v]--;
            dp[v] = max(dp[v], dp[u] + 1);
            if (indeg[v] == 0) bfs.push(v); 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] >= k-1) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;
    lli mi = INF, mx = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].clear();
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }
    for (int i = 0; i < m; i++) {
        lli u, v; cin >> u >> v;
        g[u].pb(v);
    }
    lli L = mi, R = mx, ans = INF;
    while (L <= R) {
        lli mid = (L + R) / 2;
        if (check(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
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