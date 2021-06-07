#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1369/problem/D
lli dp[2000001];
int main() {
    dp[0] = dp[1] = dp[2] = 0;
    for (int i = 3; i <= 2000000; i++) {
        dp[i] = 2*dp[i-2] + dp[i-1] + (i%3 == 0)*4;
        dp[i] = dp[i] % MOD;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
}
