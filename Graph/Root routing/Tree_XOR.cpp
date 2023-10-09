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

// https://codeforces.com/contest/1882/problem/D
// Intuition: Find the operation and subtree for each node setting any node as root
//            Do root routing when travering u->v

vi g[N+1];
lli st[N+1], op[N+1], a[N+1];
lli n;

void dfs(int u, int p) {
    st[u]++;
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
            st[u] += st[v];
            op[u] += st[v] * (a[u] ^ a[v]) + op[v];
        }
    }
}

void dfs2(int u, int p, vector<lli> &ans) {
    ans[u] = op[u];
    for (int v: g[u]) {
        if (v != p) {
            st[u] -= st[v];
            op[u] = op[u] - op[v] - (a[u] ^ a[v]) * st[v];
            st[v] += st[u];
            op[v] += op[u] + (a[u]^a[v]) * st[u];
            dfs2(v, u, ans);
            st[v] -= st[u];
            op[v] = op[v] - op[u] - (a[u]^a[v])*st[u];
            op[u] += op[v] + (a[u]^a[v])*st[v];
            st[u] += st[v];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        g[i].clear(); op[i] = st[i] = 0;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1, -1);
    vector<lli> ans(n+1);
    dfs2(1, -1, ans);
    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}