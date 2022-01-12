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

const lli INF = 1e18, MOD = 998244353;
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1619/problem/G

int n, k, tt;
map<pair<int, int>, int> tmr;
map<int, vector<int>> X, Y; 
set<pair<int, int>> visit;

int dfs(pair<int, int> mine) {
    if (visit.find(mine) == visit.end()) visit.insert(mine);
    else return INT_MAX;
    int x = mine.first, y = mine.second;
    int xi = lower_bound(X[x].begin(), X[x].end(), y) - X[x].begin();
    int yi = lower_bound(Y[y].begin(), Y[y].end(), x) - Y[y].begin();
    int mi = tmr[mine];
    if (xi+1 < X[x].size() && visit.find({x, X[x][xi+1]}) == visit.end() && abs(X[x][xi+1]-y) <= k)
        mi = min(mi, dfs({x,X[x][xi+1]}));
    if (xi-1 >= 0 && visit.find({x, X[x][xi-1]}) == visit.end() && y-X[x][xi-1] <= k)
        mi = min(mi, dfs({x, X[x][xi-1]}));
    if (yi+1 < Y[y].size() && visit.find({Y[y][yi+1], y}) == visit.end() && Y[y][yi+1]-x <= k)
        mi = min(mi, dfs({Y[y][yi+1], y}));
    if (yi-1 >= 0 && visit.find({Y[y][yi-1], y}) == visit.end() && x-Y[y][yi-1] <= k)
        mi = min(mi, dfs({Y[y][yi-1], y}));
    return mi;
}

void solve() {
    cin >> n >> k;
    tt = 0;
    tmr.clear(); X.clear(); Y.clear(); visit.clear();
    vpii a;
    for (int i = 0; i < n; i++) {
        int x, y, t; cin >> x >> y >> t;
        X[x].pb(y); Y[y].pb(x);
        tmr[{x,y}] = t;
        a.pb({x,y});
    }
    for (auto &i: X) sort(i.second.begin(), i.second.end());
    for (auto &i: Y) sort(i.second.begin(), i.second.end());

    vi res;
    for (auto i: a) {
        if (visit.find(i) == visit.end()) {
            res.pb(dfs(i));
        }
    }
    sort(res.begin(), res.end()); 
    int ans = res.size() - 1;
    for (int i = 0; i < res.size(); i++) {
        ans = min(ans, max(res[i], (int)res.size()-i-2));
    }
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
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}