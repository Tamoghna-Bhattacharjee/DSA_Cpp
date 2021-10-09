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
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1561/problem/D2

void solve() {
    lli n, m; cin >> n >> m;
    vlli dp(n+5), prefSum(n+5), rngSum(n+5);
    dp[1] = prefSum[1] = 1;
    
    for (int j = 2, i = 1; j <= n; j++) {
        rngSum[j*i] = (rngSum[j*i] + dp[i]) % m;
        int x = min(n+1, j*i+j*1LL);
        rngSum[x] = (rngSum[x] - dp[i] + m) % m;
    }

    for (int i = 2; i <= n; i++) {
        rngSum[i] = (rngSum[i-1] + rngSum[i]) % m;
        dp[i] = (prefSum[i-1] + rngSum[i]) % m;
        for (int j = 2; j*i <= n; j++) {
            rngSum[j*i] = (rngSum[j*i] + dp[i]) % m;
            int x = min(n+1, j*i+j*1LL);
            rngSum[x] = (rngSum[x] - dp[i] + m) % m;
        }
        prefSum[i] = (prefSum[i-1] + dp[i]) % m;
    }
    cout << dp[n] << endl;
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