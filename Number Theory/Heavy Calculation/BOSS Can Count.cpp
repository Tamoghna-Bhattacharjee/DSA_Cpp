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

// https://codeforces.com/contest/1831/problem/D

void solve() {
    lli n; cin >> n;
    vlli a(n); for (auto &i: a) cin >> i;
    vlli b(n); for (auto &i: b) cin >> i;
    
    lli ans = 0;
    // ai == aj
    map<lli, vlli> idx;
    for (lli i = 0; i < n; i++) {
        idx[a[i]].pb(i);
    }
    for (lli i = 1; i*i <= 2*n && i <= n; i++) {
        map<lli, lli> F;
        for (lli j: idx[i]) {
            ans += F[i*i - b[j]];
            F[b[j]]++;
        }
    }

    // considering ai > aj
    vector<vi> cnt(sqrt(2*n)+5, vi(n+1));
    for (int i = 0; i < n; i++) {
        if (a[i]*a[i] <= 2*n) cnt[a[i]][b[i]]++;
    }

    for (int i = 0; i < n; i++) {
        for (lli aj = 1; aj * aj <= 2*n && aj < a[i]; aj++) {
            if (a[i]*aj - b[i] >= 0 && a[i]*aj - b[i] <= n)
            ans += cnt[aj][a[i]*aj - b[i]];
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