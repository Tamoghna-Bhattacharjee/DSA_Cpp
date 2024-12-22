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
#define all(__x) __x.begin(),__x.end()

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

// Hierholzer's algorithm

vi g[N+1];
int indeg[N+1], outdeg[N+1];

int getStartNode(int n) {
    // return the start node in case of valid Eulerian path/circuit else return -1
    int root = -1;
    int cntStart = 0, cntEnd = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(outdeg[i] - indeg[i]) > 1) return -1;
        if (outdeg[i] == indeg[i] + 1) cntStart++, root = i;
        if (indeg[i] == outdeg[i] + 1) cntEnd++;
    }
    if (cntStart == 0 && cntEnd == 0) {
        for (int i = 1; i <= n; i++) {
            if (outdeg[i] > 0) return i;
        }
    }
    if (cntStart == 1 && cntEnd == 1) return root;
    return -1;
}

void dfs(int u, vi &res) {
    while (outdeg[u] > 0) {
        int v = g[u][outdeg[u] - 1];
        outdeg[u]--;
        dfs(v, res);
    }
    res.pb(u);
}

void iterative(int root, vi &res) {
    stack<int> s; s.push(root);
    while (!s.empty()) {
        int u = s.top();
        if (outdeg[u] > 0) {
            s.push(g[u][outdeg[u]-1]);
            outdeg[u]--;
        } else {
            s.pop();
            res.pb(u);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        outdeg[u]++; indeg[v]++;
    }
    int root = getStartNode(n);
    if (root == -1) {
        cout << "Invalid Eulerian path/circuit" << endl;
        return;
    }
    vi res;
    dfs(root, res);
    // iterative(root, res);
    reverse(all(res));

    if (res.size() == m + 1) debug(res);
    else cout << "Graph is disconnected and have non zero degree node in different forest\n";
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; // cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}