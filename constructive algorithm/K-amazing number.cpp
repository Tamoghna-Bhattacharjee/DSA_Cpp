#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back   
const lli INF = 1e18-1, MOD = 998244353;
const int N = 1e5;

// https://codeforces.com/contest/1417/problem/C

void solve() {
    int n; cin >> n;
    int a[n+1];
    map<int, vi> ind;
    for (int i = 1; i <= n; i++) ind[i].pb(0);
    for (int i = 1; i <= n; i++) cin >> a[i], ind[a[i]].pb(i);
    for (int i = 1; i <= n; i++) ind[i].pb(n+1);
    
    int res[n+1]; memset(res, -1, 4*n+4);
    for (int x = 1; x <= n; x++) {
        int k = 0;
        for (int i = 1; i < (int) ind[x].size(); i++) {
            k = max(ind[x][i] - ind[x][i-1], k);
        }
        while (k <= n && res[k] == -1) res[k++] = x;
    }
    for (int k = 1; k <= n; k++) cout << res[k] << " "; cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}