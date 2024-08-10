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

// https://leetcode.com/problems/regions-cut-by-slashes/description/

int n;

int findNode(int a, vi &dsu) {
    if (dsu[a] < 0) return a;
    return dsu[a] = findNode(dsu[a], dsu);
}

bool unionNode(int a, int b, vi &dsu) {
    a = findNode(a, dsu); b = findNode(b, dsu);
    if (a == b) return false;
    if (dsu[a] <= dsu[b]) swap(a, b);
    dsu[b] += dsu[a];
    dsu[a] = b;
    return true;
}

int f(int i, int j, int k) {
    return (i*n+j)*4+k;
}

void solve() {
    cin >> n;
    vector<string> a(n); for (auto &i: a) cin >> i;
    vi dsu(n*n*4, -1);
    int ans = n*n*4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) ans -= unionNode(f(i-1,j,2), f(i,j,0), dsu);
            if (j > 0) ans -= unionNode(f(i,j-1,1), f(i,j,3), dsu);
            if (a[i][j] == ' ') {
                ans -= unionNode(f(i,j,0), f(i,j,1), dsu);
                ans -= unionNode(f(i,j,1), f(i,j,2), dsu);
                ans -= unionNode(f(i,j,2), f(i,j,3), dsu);
                ans -= unionNode(f(i,j,3), f(i,j,0), dsu);
            } else if (a[i][j] == '/') {
                ans -= unionNode(f(i,j,1), f(i,j,2), dsu);
                ans -= unionNode(f(i,j,3), f(i,j,0), dsu);
            } else {
                ans -= unionNode(f(i,j,3), f(i,j,2), dsu);
                ans -= unionNode(f(i,j,0), f(i,j,1), dsu);
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