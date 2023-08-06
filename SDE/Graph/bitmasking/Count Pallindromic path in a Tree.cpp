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
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

// Idea ->
//      if (u,v) can be rearranged to form pallindrome
//              then path = (u, root) + (root,v) => can also be rearranged to pallindrome
//      A path can be rearranged to pallindrome if number of odd freq of chars is atmost 1
//      So we can just maintain the pairity instead of freq by bitmasking

vector<pair<int, int>> g[N+1];
map<lli, lli> F;

void dfs(int u, int p, int mask) {
    F[mask]++;
    for (auto to: g[u]) {
        int v = to.first, c = to.second;
        if (v != p) {
            dfs(v, u, mask ^ (1 << c));
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) g[i].clear();
    F.clear();

    vi p(n); for (auto &i: p) cin >> i;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            g[i].push_back({p[i], s[i] - 'a' + 1});
            g[p[i]].push_back({i, s[i] - 'a' + 1});
        }
    }
    dfs(0, -1, 0);
    lli ans = 0, compliment = 0;
    for (auto &i: F) {
        int mask = i.first;
        ans += i.second * (i.second - 1) / 2;
        for (int j = 1; j <= 26; j++) {
            int x = mask ^ (1 << j);
            if (F.find(x) != F.end()) compliment += F[x] * F[mask];
        }
    }
    ans += compliment / 2;
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