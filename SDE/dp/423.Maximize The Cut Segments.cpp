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
const int N = 5e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

void solve() {
    int n, x, y, z; cin >> n >> x >> y >> z;
    vector<int> a = {0,x,y,z};
    int dp[4][n+1]; memset(dp, 0, sizeof dp);
    for (int j = 1; j <= n; j++) dp[0][j] = INT_MIN;
    for (int i = 0; i < 4; i++) dp[i][0] = 0;
    
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-a[i] >= 0) dp[i][j] = max(dp[i][j], dp[i][j-a[i]] + 1);
        }
    }
    cout << dp[3][n] < 0? 0: dp[3][n] << endl;
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