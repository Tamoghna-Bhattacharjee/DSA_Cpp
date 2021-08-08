#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 3e6 + 5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://codeforces.com/contest/1549/problem/E

lli F1[N+1], F2[N+1], inv[N+1], dp[N+1][3];

void pre() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (MOD - (MOD/i)*inv[MOD%i]%MOD)%MOD;
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= N; i++) {
        F1[i] = F1[i-1] * i % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli ncr (int n, int r) {
    if (r > n) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
}

lli power(lli a, lli n) {
    lli res = 1;
    while (n > 0) {
        if (n%2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    pre();
    dp[0][0] = dp[0][1] = dp[0][2] = n;
    lli div3 = power(3, MOD-2) % MOD;
    for (int r = 1; r <= 3*n; r++) {
        dp[r][0] = (MOD + MOD + MOD + ncr(3*n, r+1) - (dp[r-1][0] * 2 % MOD) - dp[r-1][1]) % MOD;
        dp[r][0] = dp[r][0] * div3 % MOD;

        dp[r][1] = (dp[r][0] + dp[r-1][0]) % MOD;
        dp[r][2] = (dp[r][1] + dp[r-1][1]) % MOD;
    }
    while (q--) {
        int x; cin >> x;
        lli ans = (dp[x][0] + ncr(3*n, x)) % MOD;
        printf("%d\n", ans);
    }
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}