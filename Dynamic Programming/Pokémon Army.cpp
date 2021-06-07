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

// https://codeforces.com/contest/1420/problem/C1

void solve() {
    int n, q; cin >> n >> q;
    lli a[n + 1], dpEven[n + 1], dpOdd[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dpOdd, 0, sizeof(dpOdd));
    memset(dpEven, 0, sizeof(dpEven));
    
    for (int i = 1; i <= n; i++) {
        dpEven[i] = max(dpEven[i-1], dpOdd[i-1] - a[i]);
        dpOdd[i] = max(dpOdd[i-1], dpEven[i-1] + a[i]);
    }
    lli ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, max(dpEven[i], dpOdd[i]));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}