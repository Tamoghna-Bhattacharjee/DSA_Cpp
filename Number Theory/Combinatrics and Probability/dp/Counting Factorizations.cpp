#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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

const lli INF = 1e18, MOD = 998244353;
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://codeforces.com/contest/1794/problem/D

int n;
vlli a, P;
int isPrime[N+1];
lli F1[N+1], F2[N+1], inv[N+1], freq[N+1];
vector<vlli> dp;

void pre() {
    isPrime[1] = isPrime[0] = 1;
    for (int i = 2; i*i <= N; i++) {
        if (isPrime[i] == 0) {
            for (int j = i*i; j <= N; j += i) isPrime[j] = 1;
        }
    }

    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (MOD - MOD/i*inv[MOD%i]%MOD) % MOD;
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= N; i++) {
        F1[i] = i * F1[i-1] % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }

}

lli f(int i, int j) {
    if (i == P.size()) return j == n;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = F2[freq[P[i]]] % MOD * f(i+1, j) % MOD;
    if (j < n) {
        dp[i][j] += F2[freq[P[i]] - 1] % MOD * f(i+1, j+1) % MOD % MOD; 
    }
    dp[i][j] = dp[i][j] % MOD;
    return dp[i][j];
}

void solve() {
    pre();
    cin >> n;
    a = vlli(2*n); for (auto &i: a) cin >> i, freq[i]++;
    set<int> p, np;
    for (auto &i: a) {
        if (isPrime[i] == 0) p.insert(i);
        else np.insert(i);
    }
    if (p.size() < n) {cout << 0 << endl; return;}
    lli ans = F1[n] % MOD;
    for (int i: np) ans = ans * F2[freq[i]] % MOD;
    P = vlli(p.begin(), p.end());
    dp = vector<vlli>(P.size(), vlli(p.size(), -1));
    ans = ans * f(0, 0) % MOD;
    cout << ans << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}