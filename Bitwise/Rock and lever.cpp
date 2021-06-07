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

// https://codeforces.com/contest/1420/problem/B

void solve() {
    int n; cin >> n;
    lli a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, lli> msb;
    for (lli i: a) {
        for (int j = 30; j >= 0; j--) {
            lli F = 1 << j;
            if ((i & F) != 0) {
                msb[j]++; break;
            }
        }
    }
    lli cnt = 0;
    for (auto i: msb) {
        if (i.second > 1) cnt += (i.second - 1) * i.second / 2;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}