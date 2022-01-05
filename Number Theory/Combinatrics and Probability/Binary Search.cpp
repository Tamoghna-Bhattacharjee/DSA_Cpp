#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18-1, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1436/problem/C

lli F1[N+1], F2[N+1], inv[N+1];

void fact() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (MOD - MOD/i*inv[MOD%i]%MOD) % MOD;
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= N; i++) {
        F1[i] = i * F1[i-1] % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli ncr(int n, int r) {
    if (n < r) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
}

void solve() {
    int n, x, p; cin >> n >> x >> p;
    int big = n-x, small = x-1;
    int cntB = 0, cntS = 0, L = 0, R = n;
    while (L < R) {
        int mid = (L + R)/2;
        if (mid <= p) {
            if (mid != p) cntS++;
            L = mid+1;
        } else cntB++, R = mid;
    }
    lli S = ncr(small, cntS) % MOD * F1[cntS] % MOD;
    lli B = ncr(big, cntB) % MOD * F1[cntB] % MOD;
    int other = n - cntB - cntS - 1;
    lli ans = S * B % MOD * F1[other] % MOD;
    cout << ans << endl;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fact();
    int t = 1; //cin >> t;
    while (t--) solve();
}