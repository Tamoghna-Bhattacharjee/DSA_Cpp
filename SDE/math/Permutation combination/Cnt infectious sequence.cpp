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

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/count-the-number-of-infection-sequences/

vector<lli> F1, F2, inv;

void pre(int n) {
    F1 = vlli(n+1); F2 = vlli(n+1);
    inv = vlli(n+1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
    }
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= n; i++) {
        F1[i] = i * F1[i-1] % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli power(lli a, lli n) {
    lli res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res % MOD;
}

void solve() {
    int n, m; cin >> n >> m;
    vlli sick(m); for (auto &i: sick) cin >> i;
    pre(n);
    lli res = 1; 
    lli non_inf = sick[0];
    res = res * F2[sick[0]] % MOD;
    
    for (int i = 1; i < sick.size(); i++) {
        int len = sick[i] - sick[i-1] - 1;
        res = res * power(2, len-1) % MOD;
        res = res * F2[len] % MOD;
        non_inf += len;
    }
    
    int len = n-sick.back()-1;
    non_inf += len;
    res = res * F2[len] % MOD;
    res = res * F1[non_inf] % MOD;

    cout << res << endl;
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