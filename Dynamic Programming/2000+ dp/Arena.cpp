#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e15, MOD = 998244353;
const int N = 500;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1606/problem/E

int n, x; 
vector<vlli> dp;
lli F1[N+1], F2[N+1], inv[N+1];

void pre() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= N; i++) {
        F1[i] = F1[i-1] * i % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli ncr(int a, int b) {
    if (b > a) return 0;
    return F1[a] % MOD * F2[b] % MOD * F2[a-b] % MOD;
}

lli power(lli a, lli m) {
    lli res = 1;
    while (m > 0) {
        if (m%2 == 1) res = res * a % MOD;
        a = a*a % MOD;
        m /= 2;
    }
    return res % MOD;
}

lli f(int rem, int dmg) {
    if (rem == 1) return 0;
    if (rem == 0) return 1;
    if (dmg > x) return 0;
    if (dp[rem][dmg] != -1) return dp[rem][dmg];
    lli new_dmg = min(x, dmg + rem - 1);
    lli ans = 0;
    for (lli dead = 0; dead <= rem; dead++) {
        ans = (ans + ncr(rem, dead)%MOD*power(new_dmg-dmg, dead)%MOD*f(rem-dead,dmg + rem - 1)%MOD)%MOD;
    }
    return dp[rem][dmg] = ans;
}

void solve() {
    pre();
    cin >> n >> x;
    dp = vector<vlli>(n+1, vlli(x+1, -1)); 
    // dp[i][j] = i person still alive and have received j damage 
    cout << f(n, 0) << endl;
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