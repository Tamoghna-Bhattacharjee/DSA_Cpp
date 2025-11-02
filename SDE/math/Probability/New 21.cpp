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

// https://leetcode.com/problems/new-21-game/
// dp[i] = probability of reaching a sum of i at any given point
// dp[i] = dp[i-1] * 1/mx + dp[i-2] * 1/mx + ... + dp[i-mx]*1/mx
// dp[i] = {dp[i-1] + ... + dp[max(0,i-mx)]} * 1 / mx
// since we can't count prob above k so:
// dp[i] = {dp[min(i-1, k-1)] + ... + dp[max(0, i-mx)]} * 1/mx

void solve() {
    int n, k, mx; cin >> n >> k >> mx;
    if (k == 0) {cout << 1.0 << endl; return;}
    if (n >= k+mx) {cout << 1.0 << endl; return;}
    if (n < k) {cout << 0 << endl; return;}

    vector<double> dp(k+mx+1), pref(k+mx+1);
    dp[0] = 1; pref[0] = 1;
    for (int i = 1; i <= k+mx-1; i++) {
        int r = min(i - 1, k - 1), l = max(0, i-mx);
        double sum = pref[r] - (l-1 >= 0? pref[l-1]: 0);
        dp[i] = sum/mx;
        pref[i] = pref[i-1] + dp[i];
    }
    double ans = 0;
    for (int i = k; i <= n; i++) ans += dp[i];
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