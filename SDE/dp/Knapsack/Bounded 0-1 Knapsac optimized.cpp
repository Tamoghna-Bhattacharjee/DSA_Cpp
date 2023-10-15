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

/*
https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/

This is similar to bounded 0/1 knapsac problem where each element is having some freq
dp[i][j] = #sub-multiset with i unique elements having sum = j
dp[i][j] += dp[i-1][j] => Not taking ith elements (will do it seperately)
dp[i][j] += dp[i-1][j-x] + dp[i-1][j-2*x] + dp[i-1][j-3*x] + ... + dp[i-1][j-f*x]
where x = ith unique element and f => freq[x];
The above transition would give O(N*Sum) which can be costly

SUM = Σarr[i] ===> which implies #unique element is atmost sqrt(SUM)
We can reduce this to O(sum * sqrt(sum)) if we can optimizs
        dp[i][j] += dp[i-1][j-x] + dp[i-1][j-2*x] + dp[i-1][j-3*x] + ... + dp[i-1][j-f*x]

Let's see what dp[i][j+x] would be if we take the ith unique element
dp[i][j+x] = dp[i-1][j+x-x] + dp[i-1][j+x-2*x] + .... + dp[i-1][j+x-f*x]
           = dp[i-1][j] + dp[i-1][j-x] + ... + dp[i-1][j-(f-1)*x]
           = dp[i-1][j] + dp[i][j] - dp[i-1][j-f*x]

Make the similar transition for dp[i][j] ==> replacing j+x with j
dp[i][j] = dp[i-1][j-x] + dp[i][j-x] - dp[i-1][j-x-f*x]
         = dp[i-1][j-x] + dp[i][j-x] - dp[i-1][j-(f+1)*x]

    Finallu for all j for a particular i => dp[i][j] += dp[i-1][j];

so if we use 1-D array -> 
    ndp[j] = dp[j-x] + ndp[j-x] - dp[j-(f+1)*x]
    --> Overall complexity O(SUM * sqrt(SUM)) where SUM = Σarr[i]
*/


void solve() {
    int n, l, r; cin >> n >> l >> r;
    vi a(n); for (int &i: a) cin >> i;
    
    map<int, int> F;
    for (int i: a) F[i]++;
    
    vector<int> dp(r+1);
    dp[0] = 1;
    for (auto &i: F) {
        int x = i.first, cnt = i.second;
        if (x == 0) continue;
        vector<int> ndp(r+1);
        for (int j = 0; j <= r; j++) {
            if (j-x >= 0) ndp[j] = (dp[j-x] + ndp[j-x]) % MOD;
            if (j - (cnt+1) * x >= 0) 
                ndp[j] = (ndp[j] - dp[j-(cnt+1)*x] + MOD) % MOD;
        }
        for (int j = 0; j <= r; j++) ndp[j] = (ndp[j] + dp[j]) % MOD;
        dp = ndp;
    }
    lli ans = 0;
    for (int i = l; i <= r; i++) ans = (ans + dp[i]) % MOD;
    ans = ans * (F[0] + 1) % MOD;
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
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}