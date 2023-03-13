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

// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

int n;
vector<lli> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // 1st 10 primes
lli dp[1001][1 << 11];

lli f(int i, int mask, vector<int> &a) {
    if (i == n) return 1;
    if (dp[i][mask] != -1) return dp[i][mask];
    int x = mask, val = a[i];
    bool ok = true;
    for (int j = 0; j < 10; j++) {
        int cnt = 0;
        while (val % p[j] == 0) cnt++, val /= p[j];
        if (cnt > 1) ok = false;
        else if (cnt == 1) {
            if ((mask & (1 << j)) != 0) ok = false;
            else x = x | (1 << j);
        }
    }
    if (ok) dp[i][mask] = (f(i+1, mask, a) + f(i+1, x, a)) % MOD;
    else dp[i][mask] = f(i+1, mask, a) % MOD;
    return dp[i][mask];
}

void solve() {
    cin >> n;
    vi a(n); for (auto &i: a) cin >> i;
    memset(dp, -1, sizeof dp);
    cout << (f(0,0,a) - 1 + MOD) % MOD << endl;
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