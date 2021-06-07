#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back   
const lli INF = 1e18-1, MOD = 1000000007;
const int N = 1e5;

// https://codeforces.com/contest/1418/problem/C

int dp[2*N+10][2], n, a[2*N+10];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n+5; i++) dp[i][0] = dp[i][1] = 0;
    dp[0][0] = a[0], dp[0][1] = INT_MAX;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
        dp[i][1] = min(dp[i-1][0], i-2 >= 0? dp[i-2][0]: INT_MAX);
    }  
    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;  cin >> t;
    while (t--) solve();
}