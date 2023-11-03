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
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://www.codechef.com/problems/FIZZBUZZ2307?tab=statement

int n;
vi g[N+1];
int mi[N+1], mx[N+1], in[N+1], out[N+1], subTree[N+1];

void dfs(int u, int p, int lvl) {
    mi[u] = lvl;
    subTree[u]++;
    for (int v: g[u]) {
        dfs(v, u, lvl+1);
        subTree[u] += subTree[v];
    }
}

void dfs2(int u, int p) {
    if (p == -1) mx[u] = 0;
    else mx[u] = mx[p] + subTree[p] - 1 - subTree[u] + 1;
    
    for (int v: g[u]) dfs2(v, u);
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) 
        g[i].clear(), mi[i] = mx[i] = 0, in[i] = 0, out[i] = 0, subTree[i] = 0;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        in[v]++;
        out[u]++;
    }

    int root = 0;
    for (int i = 1; i <= n && root == 0; i++) {
        if (in[i] == 0) root = i;
    }
    dfs(root, -1, 0);
    dfs2(root, -1);
    vi ans(n+5);
    for (int i = 1; i <= n; i++) ans[mi[i]]++, ans[mx[i] + 1]--;
    for (int i = 1; i <= n; i++) ans[i] += ans[i-1];
    for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
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