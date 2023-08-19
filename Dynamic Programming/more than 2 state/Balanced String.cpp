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

// https://codeforces.com/contest/1860/problem/D

string s;
int n;
int dp[101][101][5001], cnt[2], need;
// dp[i][cnt0][cnt01] => num of changes for s[0...i] having cnt0 0's in prefix and 
// cnt01 01's in prefix

int f(int i, int cnt0, int cnt01) {
    if (i >= n) return cnt0 == cnt[0] && cnt01 == need? 0: 1e9;
    if (cnt0 > cnt[0] || cnt01 > need) return 1e9;
    if (dp[i][cnt0][cnt01] != -1) return dp[i][cnt0][cnt01];
    
    dp[i][cnt0][cnt01] = 1e9;
    int x = (s[i] != '0') + f(i+1, cnt0+1, cnt01);
    int y = (s[i] != '1') + f(i+1, cnt0, cnt01 + cnt0);
    return dp[i][cnt0][cnt01] = min(dp[i][cnt0][cnt01], min(x, y));
}

void solve() {
    cin >> s; n = s.size();
    memset(cnt, 0, sizeof cnt);
    memset(dp, -1, sizeof dp);
    for (char i: s) cnt[i-'0']++;
    need = cnt[0]*cnt[1]/2;

    cout << f(0,0,0)/2 << endl;
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