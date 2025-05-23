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
const int N = 1000;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/domino-and-tromino-tiling/
/*
dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3] + dp[n-4] + ... + dp[0])
dp[n+1] = dp[n] + dp[n-1] + 2*(dp[n-2]+dp[n-3] + ... + dp[0])
dp[n+1] = dp[n] + dp[n-2] + dp[n-1] + dp[n-2] + 2*(dp[n-3] + dp[n-4] + ... + dp[0])
dp[n+1] = dp[n] + dp[n-2] + dp[n]
dp[n+1] = 2*dp[n] + dp[n-2]
dp[n] = 2*dp[n-1] + dp[n-3]
*/

lli dp[N+1];

void pre() {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (i-3 >= 0) (dp[i] += dp[i-3]%MOD) %= MOD;
        (dp[i] += 2*dp[i-1]%MOD) %= MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t; pre();
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}