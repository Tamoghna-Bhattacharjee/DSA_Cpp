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

// https://leetcode.com/problems/construct-string-with-minimum-cost/

vector<vi> trie;
vector<vlli> val;
int nxt = 0;

void insertString(string &s, lli cost) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (trie[cur][s[i]-'a'] == 0) {
            trie.pb(vi(26));
            val.pb(vlli(26, INF));
            trie[cur][s[i]-'a'] = ++nxt;
        }
        if (i == s.size() - 1) val[cur][s[i]-'a'] = min(cost, val[cur][s[i]-'a']);
        cur = trie[cur][s[i]-'a'];
    }
}

vpii getIdx(string &target, int idx) {
    vpii ans;
    int cur = 0;
    while (idx < target.size()) {
        int ch = target[idx] - 'a';
        if (val[cur][ch] != INF) ans.pb({idx, val[cur][ch]});
        if (trie[cur][ch] != 0) cur = trie[cur][ch];
        else break;
        idx++;
    }
    return ans;
}

lli f(int i, string &target, vlli &dp) {
    if (i >= target.size()) return 0;
    if (dp[i] != -1) return dp[i];
    lli ans = INF;
    int cur = 0, idx = i;
    while (i < target.size()) {
        int ch = target[i] - 'a';
        if (val[cur][ch] != INF) ans = min(ans, val[cur][ch] + f(i+1, target, dp));
        if (trie[cur][ch] != 0) cur = trie[cur][ch];
        else break;
        i++;
    }
    return dp[idx] = ans;
}

void solve() {
    string target; cin >> target;
    int n; cin >> n;
    vector<string> words(n); for (auto &i: words) cin >> i;
    vi costs(n); for (auto &i: costs) cin >> i;
    
    trie = vector<vi>(1, vi(26));
    val = vector<vlli>(1, vlli(26, INF));

    for (int i = 0; i < n; i++) insertString(words[i], costs[i]);
    vlli dp(target.size(), -1);
    lli ans = f(0, target, dp);
    if (ans >= INF) ans = -1;
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