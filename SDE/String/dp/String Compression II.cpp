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

// https://leetcode.com/problems/string-compression-ii/

void solve() {
    string s; int k;
    cin >> s >> k;
    int n = s.size(); s = "#" + s;
    vector<vector<int>> pref(n+1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1];
        pref[i][s[i]-'a']++;
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 1000));
    dp[0][0] = 0;
    //for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - 1 >= 0) dp[i][j] = dp[i-1][j-1]; //delete ith char
            for (int l = 1; l <= i; l++) {
                int cnt = pref[i][s[i]-'a'] - pref[l-1][s[i]-'a'];
                int del = (i-l+1) - cnt;
                if (j - del >= 0) {
                    string v = to_string(cnt);
                    int len = v.size();
                    dp[i][j] = min(dp[i][j], dp[l-1][j-del]+(cnt == 1? 1: 1 + len));
                }
            }
        }
    }
    cout << dp[n][k] << endl;
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