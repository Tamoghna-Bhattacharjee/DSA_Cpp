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


void solve() {
    int n; cin >> n;
    int a[2*n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < 2*n; i++) a[i] = a[i-n];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> mp, cnt;
    for (int i = 0; i < n; i++) mp[b[i]] = i;
    for (int i = 0; i < 2*n; i++) cnt[i-mp[a[i]]]++;
    int mx = 0;
    for (auto i: cnt) mx = max(mx, i.second);
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
}