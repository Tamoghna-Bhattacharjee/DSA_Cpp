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

// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

lli countSubArr(vi &a, lli target) {
    lli L = 0, R = 0, sum = 0;
    lli ans = 0;
    while (R < a.size()) {
        sum += a[R];
        while (L <= R && sum > target) sum -= a[L++];
        ans += R-L+1;
        R++;
    }
    return ans;
}

lli getSumTill(vi &a, lli k) {
    lli L = 0, R = accumulate(all(a), 0LL), kthsum = 0, cnt = 0;
    while (L <= R) {
        lli mid = (L + R) >> 1;
        lli x = countSubArr(a, mid); 
        if (x >= k) kthsum = mid, cnt = x, R = mid - 1;
        else L = mid + 1;
    }
    L = 0, R = 0;
    lli win = 0, tot = 0, sum = 0;
    while (R < a.size()) {
        sum += (R-L+1)*a[R];
        win += a[R];
        while (L <= R && win > kthsum) {
            sum -= win;
            win -= a[L++];
        }
        tot += sum;
        R++;
    }
    return (tot - (cnt - k) * kthsum) % MOD;
}

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vi a(n); for (auto &i: a) cin >> i;
    cout << (getSumTill(a, r) - getSumTill(a, l-1) + MOD) % MOD << endl;
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