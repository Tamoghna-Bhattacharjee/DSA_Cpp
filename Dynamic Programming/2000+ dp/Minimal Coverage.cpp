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

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const lli INF = 1e18, MOD = 998244353;
const int N = 2e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1579/problem/G

int n;
vi a;
vector<vi> dp; 
// dp[i][j] -> min total displacement for i seg with endpoint being j dist from start

void solve() {
    cin >> n;
    a = vi(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp = vector<vi>(n+1, vi(2005, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2000; j++) {
            if (dp[i-1][j] == INT_MAX) continue; 
            // move left
            int cur = max(0, j-a[i]);
            int inc = max(0, a[i]-j);
            dp[i][cur] = min(dp[i][cur], dp[i-1][j] + inc);

            // move right
            cur = j+a[i];
            inc = max(0, cur - dp[i-1][j]);
            if (cur <= 2000) dp[i][cur] = min(dp[i][cur], dp[i-1][j]+inc);
        }
    }
    int ans = INT_MAX;
    for (int i: dp[n]) ans = min(ans, i);
    cout << ans << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}