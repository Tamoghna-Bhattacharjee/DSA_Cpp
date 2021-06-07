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

// https://codeforces.com/contest/1362/problem/C

lli dp[62];

void mkdp() {
    dp[0] = 1;
    lli sum = 1;
    for (int i = 1; i <= 60; i++) {
        dp[i] = (i+1) + sum;
        sum += dp[i];
    }
}


lli getPref(int ind) {
    lli res = 0;
    for (int i = 0; i < ind; i++) res += dp[i];
    return res;
}

void solve() {
    lli n; cin >> n;
    lli sum = 0;
    for (int i = 62; i >= 0; i--) {
        lli F = (ll)1 << i;
        if (n & F) {
            sum += getPref(i) + (i+1);
        }
    }
    cout << sum << endl; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    mkdp();
    while (t--) solve();
}
