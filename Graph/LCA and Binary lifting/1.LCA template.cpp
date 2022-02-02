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
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1304/problem/E

int LCA[N+1][21], level[N+1];
vi g[N+1];

void dfs(int u, int p) {
    level[u] = level[p] + 1;
    LCA[u][0] = p;
    for (int v: g[u]) {
        if (v != p) dfs(v, u);
    }
}

void mkLCA() {
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            if (LCA[i][j-1] != -1) LCA[i][j] = LCA[LCA[i][j-1]][j-1];
        }
    }
}

int getLCA(int a, int b) {
    if (level[a] > level[b]) swap(a,b);
    int d = level[b] - level[a];
    while (d) {
        int  i = log2(d);
        b = LCA[b][i];
        d -= 1 << i;
    }
    if (a == b) return b;
    for (int i = 19; i >= 0; i--) {
        if (LCA[a][i] != -1 && LCA[b][i] != -1 && LCA[a][i] != LCA[b][i])
            a = LCA[a][i], b = LCA[b][i];
    }
    return LCA[a][0];
}

int getDist(int a, int b) {
    return level[a] + level[b] - 2*level[getLCA(a,b)];
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    memset(LCA, -1, sizeof LCA);
    level[0] = -1;
    dfs(1,0);
    mkLCA();
    int q; cin >> q;
    while (q--) {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        vi v = {getDist(a,b), getDist(a,x)+1+getDist(b,y), getDist(a,y)+1+getDist(b,x)};
        bool ok = false;
        for (int i: v) {
            if (i <= k && i%2 == k%2) ok = true;
        }
        cout << YN[ok] << endl;
    }
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