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

// https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game/description/

// One of the very rare problem where the conecpt of binary lifting being used on graph
// Generally used in tree to find LCA

void solve() {
    lli n, k; cin >> n >> k;
    vlli a(n); for (auto &i: a) cin >> i;
    vector<vlli> par(n, vlli(40, -1)), sum(n, vlli(40));
    for (int i = 0; i < n; i++) {
        par[i][0] = a[i];
        sum[i][0] = a[i];
    }
    for (int j = 1; j < 39; j++) {
        for (int i = 0; i < n; i++) {
            if (par[i][j-1] != -1) {
                par[i][j] = par[par[i][j-1]][j-1];
                sum[i][j] = sum[i][j-1] + sum[par[i][j-1]][j-1];
            }
        }
    }
    lli ans = 0;
    for (int i = 0; i < n; i++) {
        lli cur = i, res = i, d = k;
        while (d) {
            lli j = log2(d);
            res += sum[cur][j];
            cur = par[cur][j];
            d -= 1LL << j;
        }
        ans = max(ans, res);
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