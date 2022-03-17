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

// https://codeforces.com/contest/1646/problem/D

int n;
vi g[N+1];
vector<vector<pair<int, int>>> dp; 
// dp[i][0] -> {#good vertex in subtree of i, sum of vertex in subtree of i}
// 0 -> considering curr node to be bad
// 1 -> considering curr node as good
vi res;
int sum, good_node;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void dfs(int u, int p) {
    pair<int, int> good, bad;
    good = {1, g[u].size()};
    bad = {0, 1};
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
            good.first += dp[v][0].first;
            good.second += dp[v][0].second;
            if (cmp(dp[v][0], dp[v][1])) 
                bad.first += dp[v][0].first, bad.second += dp[v][0].second;
            else 
                bad.first += dp[v][1].first, bad.second += dp[v][1].second;
        }
    }
    dp[u][1] = good;
    dp[u][0] = bad;
}

void dfs2(int u, int p, bool isGood) {
    bool good = false;
    if (!isGood || cmp(dp[u][0], dp[u][1])) good = false;
    else good = true;
    if (good) res[u] = g[u].size();
    else res[u] = 1;
    sum += res[u];
    for (int v: g[u]) {
        if (v != p) dfs2(v, u, !good);
    }
}

void solve() {
    cin >> n; 
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dp = vector<vpii>(n+1, vpii(2));
    res = vi(n+1);
    good_node = 0; sum = 0;
    dfs(1,-1);
    dfs2(1,-1, true);
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == res[i]) good_node++;
    }
    cout << good_node << " " << sum << endl;
    for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << endl;
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