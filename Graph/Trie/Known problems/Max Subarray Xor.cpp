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

// https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
// https://codeforces.com/contest/1847/problem/C

vector<vi> trie;
int nxt;

void insert(int val) {
    int cur = 0;
    for (int i = 10; i >= 0; i--) {
        int x = (val >> i) & 1;
        if (trie[cur][x] == 0) {
            trie[cur][x] = ++nxt;
            trie.pb(vi(2));
        }
        cur = trie[cur][x];
    }
}

int qry(int val) {
    int ans = 0, cur = 0;
    for (int i = 10; i >= 0; i--) {
        int x = (val >> i) & 1;
        if (trie[cur][1-x]) {
            ans |= 1 << i;
            cur = trie[cur][1-x];
        } else cur = trie[cur][x];
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); for (auto &i: a) cin >> i;
    trie = vector<vi>(1, vi(2));
    nxt = 0;
    int pref_xor = 0, mx = 0;
    insert(pref_xor);
    for (int i: a) {
        pref_xor ^= i;
        insert(pref_xor);
        mx = max(mx, qry(pref_xor));
    }
    cout << mx << endl;
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