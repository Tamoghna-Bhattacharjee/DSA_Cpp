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

// https://leetcode.com/problems/count-stepping-numbers-in-range/

// Given two positive integers low and high represented as strings, 
//find the count of stepping numbers in the inclusive range [low, high].
//A stepping number is an integer such that all of its adjacent digits have an 
//absolute difference of exactly 1.

lli dp[100][10][2][2]; // dp[i][lastDigit][is Prefix Zero][tight]

lli util(string &s, int i, int last, bool isZero, bool tight) {
    if (i >= s.size()) return 1;
    if (dp[i][last][isZero][tight] != -1) return dp[i][last][isZero][tight];
    int end = tight? s[i]-'0': 9;
    lli ans = 0;
    for (int j = 0; j <= end; j++) {
        if (isZero) {
            ans += util(s, i+1, j, j == 0, tight & (end == j));
        } else if (abs(last-j) == 1) {
            ans += util(s, i+1, j, false, tight & (end == j));
        }
        ans = ans % MOD;
    }
    return dp[i][last][isZero][tight] = ans;
}

lli f(string &s) {
    memset(dp, -1, sizeof dp);
    return util(s, 0, 0, 1, 1);
}

void solve() {
    string low, high; cin >> low >> high;
    lli ans = (f(high) - f(low) + MOD) % MOD;
    bool ok = true;
    for (int i = 0; i < low.size()-1; i++) 
        ok = ok && abs(low[i+1]-low[i]) == 1;
    if (ok) ans++;
    ans = ans % MOD;
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