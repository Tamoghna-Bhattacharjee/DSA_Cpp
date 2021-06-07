#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

lli dp[1005][1005][2];

// https://codeforces.com/contest/1498/problem/C

void solve() {
    int n, k; cin >> n >> k;
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][k][0] = 1;
    // dir - 0 -> L to R        1 -> R to L
    int ans = 1;
    for (int j = k-1, dir = 1; j >= 1; j--, dir ^= 1) {
        if (dir == 1) {
            for (int i = n; i >= 1; i--) {
                dp[i][j][dir] += dp[i+1][j][dir] + dp[i-1][j+1][1^dir];
                dp[i][j][dir] %= MOD;
            }
            ans = (ans + dp[1][j][dir]) % MOD;
        } else {
            for (int i = 1; i <= n; i++) {
                dp[i][j][dir] += dp[i-1][j][dir] + dp[i+1][j+1][1^dir];
                dp[i][j][dir] %= MOD;
            }
            ans = (ans + dp[n][j][dir]) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}