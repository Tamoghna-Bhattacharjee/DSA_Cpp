#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back  
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) cout << i << " "; cout << endl;}

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 1e5;  

//https://codeforces.com/contest/1422/problem/C

lli power(lli a, int n) {
    lli res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    int n = (int) s.size();
    vector<lli> suf(n), pref(n);
    for (int i = 1; i < n; i++) {
        pref[i] = 1LL * i %MOD * (i+1) % MOD * power(2, MOD-2) %MOD * power(10, n-i-1) % MOD;
    }
    suf[n-1] = 0;
    lli p = 1;
    for (int i = n-2, cnt = 1; i >= 0; i--, cnt++) {
        suf[i] = (suf[i+1] + cnt * p % MOD) % MOD; 
        p = p * 10 % MOD;
    }
    for (int i = 0; i < n; i++) {
        suf[i] = suf[i] * (s[i] - '0') % MOD;
        pref[i] = pref[i] * (s[i] - '0') % MOD;
    }
    lli sum = 0;
    for (int i = 0; i < n; i++) sum = (sum + pref[i] + suf[i]) % MOD;
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}