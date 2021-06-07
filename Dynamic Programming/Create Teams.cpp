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

// https://codeforces.com/contest/1380/problem/C

void solve() {
    int n, a;
    lli x; cin >> n >> x;
    int dp[n];
    vector<lli> arr;
    for (int i = 0; i < n; i++) cin >> a, arr.pb(a);
    sort(arr.begin(), arr.end());
    int mx = 0;
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] >= x) dp[i] = n-i;
        else {
            int size = ceil((float) x/ arr[i]);
            int R = i+size;
            if (R == n) dp[i] = 1;
            else if (R > n) dp[i] = 0;
            else dp[i] = 1 + dp[R];
        }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}

