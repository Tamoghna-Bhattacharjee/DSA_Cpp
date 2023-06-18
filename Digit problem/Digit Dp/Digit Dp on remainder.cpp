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

// https://codeforces.com/contest/628/problem/D

lli dp[2000][2000][2]; // -> dp[i][rem][tight]
lli m, d;

lli digitDp_util(string &s, int i, int rem, int tight) {
    if (i >= s.size()) return rem == 0;
    if (dp[i][rem][tight] != -1) return dp[i][rem][tight];
    int end = tight? s[i]-'0': 9;
    lli res = 0;
    if (i % 2 == 1) {
        if (d <= end) res += digitDp_util(s, i+1, (rem*10+d) % m, (tight & (d == end)));
        res %= MOD;
    } else {
        for (int j = 0; j <= end; j++) {
            if (j == d) continue;
            res += digitDp_util(s, i+1, (rem*10+j) % m, (tight & (j == end)));
            res %= MOD;
        }
    }
    return dp[i][rem][tight] = res;
}

lli f(string &s) {
    memset(dp, -1, sizeof dp);
    return digitDp_util(s, 0, 0, 1);
}

void solve() {
    cin >> m >> d;
    string L, R; cin >> L >> R;
    lli ans = (f(R) - f(L) + MOD) % MOD;
    bool ok = true;
    int rem = 0;
    for (int i = 0; i < L.size(); i++) {
        rem = rem * 10 + L[i]-'0';
        rem = rem % m;
        if (i%2) ok = ok && L[i]-'0' == d;
        else ok = ok && L[i]-'0' != d;
    }
    if (ok && rem == 0) ans++;
    ans = ans % MOD;
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