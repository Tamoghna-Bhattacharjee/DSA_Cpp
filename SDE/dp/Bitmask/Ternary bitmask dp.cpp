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

// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

lli p[6];

void pre() {
    p[0] = 1;
    for (int i = 1; i < 6; i++) p[i] = p[i-1] * 3;
}

int getBit(int mask, int pos) {
    return (mask / p[pos]) % 3;
}

bool isValid(int mask, int m) {
    int prev = -1;
    for (int i = 0; i < m; i++) {
        int bit = getBit(mask, i);
        if (bit == prev) return false;
        prev = bit;
    }
    return true;
}

bool isValid(int mask1, int mask2, int m) {
    for (int i = 0; i < m; i++) {
        int bit1 = getBit(mask1, i);
        int bit2 = getBit(mask2, i);
        if (bit1 == bit2) return false;
    }
    return true;
}

void solve() {
    int m, n; cin >> m >> n;
    vector<int> valid;
    for (int mask = 0; mask < p[m]; mask++) {
        if (isValid(mask, m)) valid.pb(mask);
    }

    unordered_map<int, vi> g;
    for (int i: valid) {
        for (int j: valid) {
            if (isValid(i, j, m)) g[i].pb(j);
        }
    }

    vlli dp(p[m]);
    for (int mask: valid) dp[mask] = 1;

    for (int i = 1; i < n; i++) {
        vlli ndp(p[m]);
        for (int mask: valid) {
            for (int cmp: g[mask]) (ndp[cmp] += dp[mask]) %= MOD;
        }
        dp = ndp;
    }

    lli ans = 0;
    for (auto i: dp) (ans += i) %= MOD;
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