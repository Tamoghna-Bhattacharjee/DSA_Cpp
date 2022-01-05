#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e9-1, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1462/problem/E2

lli F1[2*N+5], F2[2*N+5], inv[2*N+5];

void fact() {
    inv[1] = 1;
    for (int i = 2; i <= 2*N; i++) inv[i] = (MOD - MOD/i * inv[MOD%i]%MOD) % MOD;
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= 2*N; i++) {
        F1[i] = i*F1[i-1] % MOD;
        F2[i] = inv[i] * F2[i-1] % MOD;
    }
}

lli ncr(int n, int r) {
    if (r > n) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
}


void solve () {
    int n, m, k; cin >> n >> m >> k;
    vi cnt(n+1), prefSum(n+1);
    set<int> s;
    for (int i = 1; i<= n; i++) {
        int x; cin >> x;
        cnt[x]++;
        s.insert(x);
    }
    for (int i = 1; i <= n; i++) prefSum[i] = prefSum[i-1] + cnt[i];
    lli ans = 0;
    for (int i: s) {
        int mx = min(i+k, n);
        int x = prefSum[mx] - prefSum[i-1];
        ans = (ans + ncr(x, m) - ncr(x - cnt[i], m) + MOD) % MOD;
    }
    cout << ans << endl;
}

int main() {
    fact();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    while (t--) solve();
}