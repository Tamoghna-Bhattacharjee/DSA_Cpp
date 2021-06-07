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

// https://codeforces.com/contest/1389/problem/B

const int N = 1e5;
int arr[N], dp[N+1][6];

int f(int i, bool canLeft, int n, int k, int z) {
    if (k == 0) return dp[k][z] = arr[i];
    if (dp[k][z] != 0) return dp[k][z];
    dp[k][z] += arr[i];
    int a = 0, b = 0;
    if (canLeft && z > 0 && i-1 >= 0) a = f(i-1, !canLeft, n, k-1, z-1);
    if (i+1 < n) b = f(i+1, true, n, k-1, z);
    return dp[k][z] += max(a, b);
}

void solve() {
    int n, z, k;
    cin >> n >> k >> z;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= z; j++) dp[i][j] = 0;
    
    cout << f(0, true, n, k, z) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}