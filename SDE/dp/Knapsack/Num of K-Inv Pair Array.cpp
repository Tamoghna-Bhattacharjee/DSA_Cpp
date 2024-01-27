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

// https://leetcode.com/problems/k-inverse-pairs-array/
/*
    Idea:- 
    Let's consider the range x = [1...n]
    If we put 1 in 1st -> Contribution of 1 being 1st = 0
    If we put 2 in 1st -> Contribution of 2 being 1st = 2-1 = 1
    If we put 3 in 1st -> Contribution of 3 being 1st = 3-1 = 2
    ....
    If we put x in 1st -> Contribution of x being 1st = x-1

    Let's define dp[i][j] -> #ways to get j inv with range [1...i]
    
    dp[i][j] = dp[i-1][j-(1-1)] + dp[i-1][j-(2-1)] + ... + dp[i-1][j-(i-1)]
             = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-i+1]

    So replace j with j+1
    dp[i][j+1] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-i+2]
    ==> dp[i][j+1] = dp[i-1][j] + dp[i][j] - dp[i-1][j-i+1]

    Now substitute j = j+1
    dp[i][j] = dp[i-1][j-1] + dp[i][j-1] - dp[i-1][j-i]

    Also for a range [1...i] Max num of inv => i * (i-1) / 2
*/

void solve() {
    int n, k; cin >> n >> k;
    lli dp[n+1][k+1]; memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j > i*(i-1)/2) continue;
            (dp[i][j] = dp[i-1][j] + dp[i][j-1]) %= MOD;
            if (j-i >= 0)
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
                
        }
    }
    cout << dp[n][k] << endl;
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