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

// https://codeforces.com/contest/1859/problem/D

int getIdx(vpii &seg, int x, int n) {
    int L = 1, R = n, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (seg[mid].first <= x) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    return ans;
} 

void solve() {
    int n; cin >> n;
    vpii seg(n+1);
    for (int i = 1; i <= n; i++) {
        int l, r, a, b; cin >> l >> r >> a >> b;
        seg[i] = {l, b};
    }
    sort(seg.begin() + 1, seg.end());
    for (int i = 2; i <= n; i++) {
        if (seg[i].first <= seg[i-1].second)
            seg[i].second = max(seg[i].second, seg[i-1].second);
    }
    for (int i = n-1; i >= 1; i--) {
        if (seg[i+1].first <= seg[i].second) 
            seg[i].second = max(seg[i].second, seg[i+1].second);
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int idx = getIdx(seg, x, n);
        cout << max(x, seg[idx].second) << " ";
    }
    cout << endl;
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