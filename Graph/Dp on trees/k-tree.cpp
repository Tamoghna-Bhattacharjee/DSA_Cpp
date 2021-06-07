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
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h);}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/431/problem/C

lli f(int k, int n, int d) {
    lli dp[n+1][n+1][2]; memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int h = 1; h <= n; h++) {
        for (int j = 0; j <= n; j++) {
            for (int edge = 1; edge <= min(j,k); edge++) {    
                dp[h][j][1] = (dp[h][j][1] + dp[h-1][j-edge][1]) % MOD;
                if (edge >= d) dp[h][j][1] = (dp[h][j][1] + dp[h-1][j-edge][0]) % MOD;
                else dp[h][j][0] = (dp[h][j][0] + dp[h-1][j-edge][0]) % MOD;
            }
        }
    }
    lli ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + dp[i][n][1]) % MOD;
    return ans;
}

void solve() {
    int n, k, d; cin >> n >> k >> d;
    cout << f(k,n,d) << endl;
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
    for (int h = 1; h <= t; h++) {
        //cout << "Case #" << h << ": ";
        solve();
    }
}