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

// https://leetcode.com/problems/find-all-good-strings/

vi LPS;
lli dp[500][50][2];

void makeLPS(string &s) {
    int n = s.size();
    LPS = vi(n);
    int i = 1, j = 0;
    while (i < n) {
        if (s[i] == s[j]) LPS[i++] = ++j;
        else {
            if (j == 0) i++;
            else j = LPS[j-1];
        }
    }
}

lli digitDp(int i, int j, bool tight, string &s, string &evil) {
    if (j >= evil.size()) return 0;
    if (i >= s.size()) return 1;
    if (dp[i][j][tight] != -1) return dp[i][j][tight];
    char end = tight ? s[i]: 'z';
    lli ans = 0;
    for (char ch = 'a'; ch <= end; ch++) {
        int nj = j;
        while (nj > 0 && evil[nj] != ch) nj = LPS[nj-1];
        if (ch == evil[nj]) nj++;
        ans += digitDp(i+1, nj, (tight & (ch == end)), s, evil);
        ans %= MOD;
    }
    return dp[i][j][tight] = ans;
}

lli util(string &s, string &evil) {
    memset(dp, -1, sizeof dp);
    return digitDp(0,0,1,s,evil) % MOD;
}

void solve() {
    int n; cin >> n;
    string s1, s2, evil; cin >> s1 >> s2 >> evil;
    makeLPS(evil);
    lli ans = (util(s2, evil) % MOD - util(s1, evil) % MOD + MOD) % MOD;
    bool hasEvil = false;
    for (int i = 0; i < n && !hasEvil; i++) {
        if (i+evil.size()-1 < n && s1.substr(i, evil.size()) == evil) 
            hasEvil = true;
    }
    cout << ans + (!hasEvil) << endl;
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