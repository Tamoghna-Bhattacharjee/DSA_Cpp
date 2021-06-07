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

// https://codeforces.com/contest/1420/problem/D

lli F1[3*N+1], F2[3*N+1], inv[3*N+1];

void factorials() {
    inv[1] = 1;
    for (int i = 2; i <= 3*N; i++) {
        inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
    }
    F1[0] = F2[0] = 1;
    for (int i = 1; i < 3*N + 1; i++) {
        F1[i] = i * F1[i-1] % MOD;
        F2[i] = inv[i] * F2[i-1] % MOD;
    }
}

lli ncr(int n, int r) {
    if (n < r) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
}

void solve() {
    factorials();
    int n, k, l, r; cin >> n >> k;
    map<int, int> st, en;
    set<int> s;
    for (int i = 0; i < n; i++) cin >> l >> r, s.insert(l), s.insert(r), st[l]++, en[r]++;
    lli curr = 0, ans = 0;
    for (int i: s) {
        curr += st[i];
        ans = (ans + ncr(curr, k) - ncr(curr - st[i], k) + MOD) % MOD;
        curr -= en[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}