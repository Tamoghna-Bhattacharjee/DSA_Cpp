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

// https://codeforces.com/problemset/problem/1792/D

vector<vi> trie;
int nxt = 0;

void insert(vi &x, int m) {
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        if (trie[cur][x[i]] == 0) {
            nxt++; trie.pb(vi(m+1));
            trie[cur][x[i]] = nxt;
            cur = nxt;
        } else cur = trie[cur][x[i]];
    }
}  

int getMaxK(vi &x, int m) {
    int k = 0, cur = 0;
    for (int i = 1; i <= m; i++) {
        if (trie[cur][x[i]] == 0) break;
        else k++, cur = trie[cur][x[i]];
    }
    return k;
} 

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> a;
    trie = vector<vi>(1, vi(m+1));
    nxt = 0;
    for (int i = 0; i < n; i++) {
        vi x(m+1), inv(m+1);
        for (int j = 1; j <= m; j++) cin >> x[j], inv[x[j]] = j;
        a.pb(x);
        insert(inv, m);
    }
    for (auto i: a) cout << getMaxK(i, m) << " "; cout << endl;
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