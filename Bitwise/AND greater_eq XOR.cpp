#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://codeforces.com/contest/1557/problem/C

// (xor=and) (xor=and) ... (xor > and) ....anything... => xor > and
// ans = (2^n)^k - #ways xor > and

lli power(lli a, lli n) {
    lli res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res % MOD;
}

void solve() {
    lli n, k; cin >> n >> k;
    lli ans = 0;
    if (n%2 == 1) {
        lli x = power(2, n-1) - 1;
        for (lli i = 0; i < k; i++) {
            ans = (ans + power(2, n*i) * x % MOD * power(power(2,n-1)+1, k-i-1)) % MOD;
        }
    } else {
        lli x = power(2, n-1);
        for (lli i = 0; i < k; i++) {
            ans = (ans + power(2,n*i) * x % MOD * power((x-1+MOD)%MOD, k-i-1) % MOD) % MOD;
        }
    }
    ans = (power(2,n*k) - ans + MOD) % MOD;
    cout << ans << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}