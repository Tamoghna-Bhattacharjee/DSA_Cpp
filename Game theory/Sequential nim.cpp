#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back  

// https://codeforces.com/contest/1382/problem/B

void solve() {
    int n; cin >> n;
    int a[n], dp[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) dp[i] = 1;
        else {
            if (a[i] > 1) dp[i] = 1;
            else dp[i] = 1-dp[i+1];
        }
    }
    if (dp[0] == 1) cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}

