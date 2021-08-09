#include <bits/stdc++.h>
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
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://www.geeksforgeeks.org/count-of-permutations-such-that-sum-of-k-numbers-from-given-range-is-even/

void solve() {
    lli L, R, k; cin >> L >> R >> k;
    lli len = R-L+1;
    lli even_cnt = 0, odd_cnt = 0;
    if (len % 2 == 0) even_cnt = len/2, odd_cnt = len/2;
    else {
        if (L%2 == 0) even_cnt = (len+1)/2, odd_cnt = len/2;
        else odd_cnt = (len+1)/2, even_cnt = len/2;
    }
    lli dp[k+1][2]; memset(dp, 0, sizeof dp); 
    // dp[x][0] -> #ways to get even sum of x numbers
    // dp[x][1] -> #ways to get odd sum of x numbers
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        dp[i][0] = dp[i-1][0]*even_cnt + dp[i-1][1] * odd_cnt;
        dp[i][1] = dp[i-1][0]*odd_cnt + dp[i-1][1] * even_cnt;
    }
    cout << dp[k][0] << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}