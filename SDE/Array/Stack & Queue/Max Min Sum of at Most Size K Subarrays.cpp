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
https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/

Whenever problem demands minimum or maximum for sub-arrays 
then go with monotonic queue/stack
*/

lli calc(lli l, lli r, lli k) {
    lli ans = 0;
    r = min(r, k);
    lli c1 = r;
    lli c2 = min(l, k-r) * r;
    lli rem = max(0LL, l - min(l, k-r));
    lli L = max(0LL, r-rem), R = max(0LL, r-1);
    lli c3 = 0;
    if (L <= R) c3 = (R-L+1) * (L + R) / 2;
    return c1 + c2 + c3;
}

lli f(vi &a, int k) {
    int n = a.size();
    vi L(n, -1), R(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) R[s.top()] = i, s.pop();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) L[s.top()] = i, s.pop();
        s.push(i);
    }
    lli ans = 0;
    for (int i = 0; i < n; i++) {
        int r = R[i]-i, l = i-L[i]-1;
        ans += 1LL * a[i] * calc(l, r, k);
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (auto &i: a) cin >> i;
    lli mx_sum =  0, mi_sum = 0;
    mx_sum = f(a, k);
    for (int &i: a) i *= -1;
    mi_sum = f(a, k);
    lli ans = mx_sum - mi_sum;
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