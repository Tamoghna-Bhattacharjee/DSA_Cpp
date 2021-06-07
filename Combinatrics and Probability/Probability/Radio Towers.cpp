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

const lli INF = 1e9-1, MOD = 998244353;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1452/problem/D

lli power(lli a, int n) {
    lli res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

void solve () {
    int n; cin >> n;
    int mid = (n+1)/2;  
    lli dp[n+1], x = 0;
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = (dp[i-1] + dp[i-2])%MOD;
    
    lli deno = power(2,n) % MOD;
    lli ans = dp[n] * power(deno, MOD-2) % MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    while (t--) solve();
}