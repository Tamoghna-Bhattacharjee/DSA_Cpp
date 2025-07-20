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

// https://leetcode.com/problems/delete-duplicate-folders-in-system/

vector<map<string, int>> trie;
vector<string> ser;
unordered_map<string, int> freq;
int nxt = 0;

void insertNode(vector<string> &a) {
    int cur = 0;
    for (auto &i: a) {
        if (trie[cur][i] == 0) {
            trie.pb(map<string, int>());
            ser.pb("");
            trie[cur][i] = ++nxt;
        }
        cur = trie[cur][i];
    }
}

void dfs1(int cur) {
    string s = "";
    for (auto &[k, v]: trie[cur]) {
        dfs1(v);
        s += k;
        s += "(" + ser[v] + ")";
    }
    ser[cur] = s;
}

void dfs2(int cur, vector<string> &x, vector<vector<string>> &ans) {
    if (freq[ser[cur]] > 1) return;
    for (auto &[k, v]: trie[cur]) {
        x.pb(k);
        dfs2(v, x, ans);
        x.pop_back();
        
    }
    if (!x.empty()) ans.pb(x);
}

void solve() {
    int n; cin >> n;
    vector<vector<string>> a(n);
    for (auto &i : a) {
        int m; cin >> m;
        while (m--) {
            string s; cin >> s;
            i.pb(s);
        }
    }

    nxt = 0;
    trie = vector<map<string, int>>(1, map<string, int>());
    ser = vector<string>(1, "");

    for (auto &i: a) {
        insertNode(i);
    }
    dfs1(0);
    for (auto &i: ser) {
        if (!i.empty()) freq[i]++;
    }
    vector<vector<string>> ans;
    vector<string> x;
    dfs2(0, x, ans);
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