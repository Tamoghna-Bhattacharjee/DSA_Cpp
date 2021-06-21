#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

void solve() {
    int n, k; // n -> #eggs, k-> Total floors
    cin >> n >> k;
    int dp[n+1][k+1]; memset(dp, 0, sizeof dp);
    for (int i = 1; i <= k; i++) dp[1][i] = i;
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
        
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            int ans = INT_MAX;
            for (int v = 1; v <= j; v++) {
                ans = min(ans, max(dp[i-1][v-1], dp[i][j-v]));
            }
            dp[i][j] = 1 + ans;
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
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}