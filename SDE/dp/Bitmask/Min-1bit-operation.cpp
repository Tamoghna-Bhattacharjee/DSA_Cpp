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

// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/
/*
Given an integer n, you must transform it into 0 using the following operations any number 
of times:

1. Change the rightmost (0th) bit in the binary representation of n.
2. Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 
   and the (i-2)th through 0th bits are set to 0.

Return the minimum number of operations to transform n into 0

Idea -> if kth bit is set, no of operation need to make it 0 => 2^(k+1) - 1
*/


void solve() {
    int n; cin >> n;
    vector<vlli> dp(31, vlli(2));
    // dp[i][j] = num of operation to make ith bit = j {0,1} such that i-1th bit
    // to 0th bit is 0
    if (n & 1) dp[0][0] = 1;
    else dp[0][1] = 1;
    for (int i = 1; i <= 30; i++) {
        if ((n >> i) & 1) {
            dp[i][1] = dp[i-1][0]; // 1000000
            dp[i][0] = min(dp[i-1][1] + 1 + (1 << i) - 1, 
                            dp[i-1][0] + (1 << (i+1)) - 1);
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + 1 + (1 << i) - 1;
        }
    }
    cout << dp[30][0] << endl;
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