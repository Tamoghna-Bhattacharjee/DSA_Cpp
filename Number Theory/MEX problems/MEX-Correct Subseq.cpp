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

// https://codeforces.com/contest/1613/problem/D

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vector<vlli> dp(n+5, vlli(2,0)); 
    //dp[x][0] -> MEX = x and subseq - [0,1,2,..,x-1]
    // dp[x][1] -> MEX = x and subseq - [0,1,2,..,x-1,x+1,x-1,x+1];
    dp[0][0] = 1;
    for (int i: a) {
        dp[i+1][0] = (2*dp[i+1][0] + dp[i][0]) % MOD;
        dp[i+1][1] = 2*dp[i+1][1] % MOD;
        if (i-1 >= 0) {
            dp[i-1][1] = (2*dp[i-1][1] + dp[i-1][0]) % MOD;
        }
    }
    lli sum = 0;
    for (vlli i: dp) sum = (sum + i[0] + i[1]) % MOD;
    sum = (sum - 1 + MOD) % MOD;
    cout << sum << endl;
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