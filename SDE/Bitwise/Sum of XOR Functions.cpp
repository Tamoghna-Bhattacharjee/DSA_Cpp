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
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://codeforces.com/contest/1879/problem/D
// intuition:- keep track of number of location from where we can get odd num of 1's

void solve() {
    int n; cin >> n;
    vi a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    lli ans = 0;
    for (int bit = 0; bit <= 30; bit++) {
        vector<int> cnt(2), sumOfL(2);
        // cnt[0] -> cnt from where we get even number of 1's
        // cnt[1] -> cnt from where we get odd number of 1's
        lli coef = 0;
        for (lli i = 1; i <= n; i++) {
            if ((a[i] >> bit) & 1) {
                swap(cnt[0], cnt[1]);
                swap(sumOfL[0], sumOfL[1]);
                cnt[1]++;
                sumOfL[1] = (sumOfL[1] + i) % MOD;
            } else cnt[0]++, sumOfL[0] = (sumOfL[0] + i) % MOD;
            coef = (coef + (cnt[1] * (i+1) % MOD - sumOfL[1] + MOD) % MOD) % MOD;
        }
        ans = (ans + coef * (1LL << bit) % MOD) % MOD;
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
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}