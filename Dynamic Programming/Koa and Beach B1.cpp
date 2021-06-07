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

// https://codeforces.com/contest/1384/problem/B1

int n, k, l;
int d[202], dp[202][202], tide[202];

int f(int x, int time) {
    if (x == n+1) return dp[x][time % (2*k)] = 1;
    if (dp[x][time % (2*k)] != -1) return dp[x][time % (2*k)];

    dp[x][time % (2*k)] = 0;
    if (d[x] + tide[(time+1) % (2*k)] <= l && f(x, time+1) == 1) return dp[x][time % (2*k)] = 1;
    if (d[x+1] + tide[(time+1) % (2*k)] <= l && f(x+1, time+1) == 1) return dp[x][time % (2*k)] = 1;
    return dp[x][time % (2*k)] = 0;
}

void solve() {
    cin >> n >> k >> l;
    for (int i = 0; i < 2*k; i++) tide[i] = i <= k? i: 2*k-i;
    for (int i = 1; i <= n; i++) cin >> d[i];
    d[0] = d[n+1] = -k;
    for (int i = 0; i<= n+1; i++) 
        for (int j = 0; j < 2*k; j++) dp[i][j] = -1;
    if (f(0, 0) == 1) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}