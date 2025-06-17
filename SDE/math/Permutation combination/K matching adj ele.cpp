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
#define all(__x) __x.begin(),__x.end()

template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

/* https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/

    - - - | - - - | - - - -
    here n = 10, k = 7,  contiguous seg = 3 = n-k
    1st seg has m choise, remaining has n-k-1 seg has m-1 choise
    Total splits = 2 = n-k-1
    #ways to get the split = nCr(n-1, n-k-1)

*/

lli F1[N+1], F2[N+1], inv[N+1];

void pre() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (MOD - ((MOD/i) * inv[MOD % i] % MOD)) % MOD;
    }
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= N; i++) {
        F1[i] = F1[i-1] * i % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli ncr(int n, int r) {
    if (r > n) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
} 

lli power(lli a, lli n) {
    lli res = 1;
    while (n) {
        if (n % 2) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    lli ans = ncr(n-1, n-1-k) % MOD * power(m-1, n-k-1) % MOD * m % MOD;
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
    int t = 1; cin >> t;
    pre();
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}