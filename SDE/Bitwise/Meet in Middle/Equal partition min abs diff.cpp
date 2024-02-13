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

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

/*
You are given an integer array nums of 2 * n integers. You need to partition nums 
into two arrays of length n to minimize the absolute difference of the sums of the 
arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
*/

void solve() {
    int n; cin >> n;
    vi a(n); for (auto &i: a) cin >> i;

    int m = n/2;
    int tot = accumulate(a.begin(), a.end(), 0);

    vector<vector<int>> L(m+1), R(m+1);

    for (int mask = 0; mask < (1 << m); mask++) {
        int lsum = 0, rsum = 0, cnt = 0;
        for (int j = 0; j < m; j++) {
            if ((mask >> j) & 1) {
                cnt++;
                lsum += a[j];
                rsum += a[m+j];
            }
        }
        L[cnt].pb(lsum);
        R[cnt].pb(rsum);
    }
    for (auto &i: L) sort(i.begin(), i.end());
    for (auto &i: R) sort(i.begin(), i.end());

    int ans = INT_MAX;
    for (int i = 0; i <= m; i++) {
        for (int x: L[i]) {
            int y = (tot - 2*x) / 2;
            auto it = lower_bound(R[m-i].begin(), R[m-i].end(), y);
            if (it == R[m-i].end()) continue;
            int p1 = x + (*it);
            int p2 = tot - p1;
            ans = min(ans, abs(p1 - p2));
            if (it != R[m-i].begin()) {
                it--;
                p1 = x + *it;
                p2 = tot-p1;
                ans = min(ans, abs(p1 - p2));
            }
        }
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