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

// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

int n, q, tot;
vector<vi> a;
vi dp;

int getArea(vector<int> &r) {
    return abs(r[2]-r[0]+1) * abs(r[3]-r[1]+1);
}

vector<int> pick() {
    int idx = upper_bound(dp.begin(), dp.end(), rand() % tot) - dp.begin();
    int x1 = a[idx][0], y1 = a[idx][1], x2 = a[idx][2], y2 = a[idx][3];
    int X = x2-x1+1, Y = y2-y1+1;
    int x = x1 + (rand() % X);
    int y = y1 + (rand() % Y);
    return {x, y};
}

void solve() {
    cin >> n >> q;
    a = vector<vi>(n, vi(4));
    dp = vi(n);
    tot = 0;

    for (int i = 0; i < n; i++) {
        for (auto &j: a[i]) cin >> j;
        dp[i] = i-1 >= 0? dp[i-1]: 0;
        dp[i] += getArea(a[i]);
    }
    tot = dp.back();

    while (q--) {
        auto ans = pick();
        debug(ans);
    }
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