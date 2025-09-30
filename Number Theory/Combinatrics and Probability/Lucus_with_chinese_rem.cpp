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

// https://leetcode.com/problems/find-triangular-sum-of-an-array/

int power(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n % 2) res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return res;
}

int ncr(int n, int r, int mod) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n-i) % mod;
        res = res * power(i+1, mod-2, mod);
    }
    return res;
}

int ncr_lucas(int n, int r, int mod) {
    if (r == 0) return 1;
    return ncr(n % mod, r % mod, mod) * ncr_lucas(n/mod, r/mod, mod);
}

int ncr(int n, int r) {
    int mod2 = ncr_lucas(n,r,2) % 2;
    int mod5 = ncr_lucas(n,r,5) % 5;
    for (int i = 1; i < 10; i++) {
        if (i % 2 == mod2 && i % 5 == mod5) return i;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    vi a(n); for (auto &i: a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = ncr(n-1, i);
        (ans += x * a[i] % 10) %= 10;
    }
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
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}