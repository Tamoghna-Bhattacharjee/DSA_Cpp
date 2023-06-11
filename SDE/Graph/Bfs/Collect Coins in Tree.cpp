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

// https://leetcode.com/problems/collect-coins-in-a-tree/description/

int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    int m = edges.size();
    vector<set<int>> g(n);
    for (auto &i: edges) {
        g[i[0]].insert(i[1]);
        g[i[1]].insert(i[0]);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1 && coins[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vector<int> p(g[u].begin(), g[u].end());
        for (int v: p) {
            g[v].erase(u);
            g[u].erase(v);
            m--;
            if (g[v].size() == 1 && coins[v] == 0) q.push(v);
        }
    }
    vector<int> leaves;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) leaves.push_back(i);
    }
    for (int u: leaves) {
        vector<int> p(g[u].begin(), g[u].end());
        for (int v: p) {
            g[v].erase(u);
            g[u].erase(v);
            m--;
        }
    }
    leaves.clear();
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) leaves.push_back(i);
    }
    for (int u: leaves) {
        vector<int> p(g[u].begin(), g[u].end());
        for (int v: p) {
            g[v].erase(u);
            g[u].erase(v);
            m--;
        }
    }
    return 2*m;
}

void solve() {
    int n, m; cin >> n >> m;
    vi coins(n); for (auto &i: coins) cin >> i;
    vector<vi> edges(m, vi(2));
    for (auto &e: edges) {
        for (auto &i: e) cin >> i;
    }
    cout << collectTheCoins(coins, edges) << endl;
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