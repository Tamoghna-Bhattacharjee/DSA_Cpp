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
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

/*
Sample problem: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/

Lucas' theorem provides a way to compute binomial coefficients modulo a prime number 
efficiently. It states that:
For a prime number p and any two non-negative integers n and r, express them in base p as:

    n = n_k p^k + n_{k-1} p^{k-1} + ... + n_1 p + n_0
    r = r_k p^k + r_{k-1} p^{k-1} + ... + r_1 p + r_0

    where ni, ri satisfies 0 <= ni, ri < p.
    Then, the binomial coefficient modulo p is given by: 
    
    lucas(n, r, p) = (n, r) mod p= ∏ (ni, ri) mod p ==> (n, r) => ncr

    lucas(n, r, p) = ncr(n%p, r%p, p) * lucas(n/p, r/p, p);

        base cond: lucas(n, 0, p) = 1
*/

lli power(lli a, lli n, lli mod) {
    lli res = 1;
    while (n > 0) {
        if (n % 2) res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return res;
}

lli ncr(lli n, lli r, lli mod) {
    // small ncr
    // This can be made fater by precomputing fact as normal
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    lli res = 1;
    for (lli i = 0; i < r; i++) {
        res = res * (n-i) % mod;
        res = res * power(i+1, mod-2, mod);
    }
    return res;
}

lli ncr_lucas(lli n, lli r, lli mod) {
    if (r == 0) return 1;
    return ncr(n % mod, r % mod, mod) * ncr_lucas(n/mod, r/mod, mod);
}

void solve() {

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
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}