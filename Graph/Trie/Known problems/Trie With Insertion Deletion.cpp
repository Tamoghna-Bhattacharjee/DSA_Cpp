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

// https://codeforces.com/contest/1851/problem/F

int n, k;
vi a;
vector<vi> trie, cnt;
int nxt;

void insertEle(int n) {
    int cur = 0;
    for (int i = k-1; i >= 0; i--) {
        int v = (n >> i) & 1;
        if (trie[cur][v] == 0) {
            trie[cur][v] = ++nxt;
            trie.pb({0,0}); // inittializing nxt node
            cnt.pb({0, 0});
        }
        cnt[cur][v]++;
        cur = trie[cur][v];
    }
}

pair<int, int> getAns(int n) {
    int cur = 0;
    int x = 0, c = 0;
    for (int i = k-1; i >= 0; i--) {
        int v = (n >> i) & 1;
        if (trie[cur][v] && cnt[cur][v]) {
            c += v * (1 << i);
            x += (1-v) * (1<<i);
            cur = trie[cur][v];
        } else {
            c += (1-v) * (1 << i);
            cur = trie[cur][1^v];
        }
    }
    return {c, x};
}

void deleteNode(int n) {
    int cur = 0;
    for (int i = k-1; i >= 0; i--) {
        int v = (n >> i) & 1;
        cnt[cur][v]--;
        cur = trie[cur][v];
    }
}

void solve() {
    cin >> n >> k;
    a = vi(n); for (auto &i: a) cin >> i;
    nxt = 0;
    trie = vector<vi>(1, vi(2));
    cnt = vector<vi>(1, vi(2));

    map<int, vi> mp;
    for (int i = 0; i < n; i++) mp[a[i]].pb(i), insertEle(a[i]);
    vi ans(3, -1);
    int mx = -1;
    for (int i: a) {
        deleteNode(i);
        auto y = getAns(i);
        insertEle(i);
        if (((i^y.second) & (y.first ^ y.second)) > mx) {
            ans[0] = *mp[i].begin();
            ans[1] = mp[y.first].back();
            ans[2] = y.second;
            ans[0]++; ans[1]++;
            if (ans[0] > ans[1]) swap(ans[0], ans[1]);
            mx = ((i^y.second) & (y.first ^ y.second));
        }
    }
    debug(ans);
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