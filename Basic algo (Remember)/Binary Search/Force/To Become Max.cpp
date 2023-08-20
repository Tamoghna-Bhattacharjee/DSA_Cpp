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

// https://codeforces.com/contest/1856/problem/C

bool check(vlli b, lli k, lli x) {
    int n = b.size();
    lli moves = 0;
    for (int i = 0; i < n-1; i++) {
        vlli a = b;
        moves = 0;
        if (a[i] <= x) moves += x-a[i], a[i] = x;
        for (int j = i+1; j < n; j++) {
            if (a[j] >= a[j-1]-1) break;
            if (j == n-1) {
                moves = INT_MAX; break;
            }
            lli op = a[j-1] - a[j] - 1;
            moves += op;
            a[j] += op;
        }
        if (moves <= k) return true;
    }
    return false;
}

void solve() {
    lli n, k; cin >> n >> k;
    vlli a(n); for (auto &i: a) cin >> i;
    lli mx = *max_element(a.begin(), a.end());
    lli L = mx+1, R = mx + k, ans = mx;
    while (L <= R) {
        lli mid = (L + R) / 2;
        if (check(a, k, mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
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