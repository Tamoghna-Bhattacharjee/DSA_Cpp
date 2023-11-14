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

// https://leetcode.com/problems/count-palindromic-subsequences/
// Intuition: Evry palindrome of len 5 -> XY_YX
// so for ecah ith element as middle element contri = prefCnt(XY from 0 to i-1)
//                                                        * sufCnt(YX from i+1 to n)

void solve() {
    string s; cin >> s;
    int n = s.size();

    lli pref[n][10][10]; memset(pref, 0, sizeof pref);
    vi cnt(10);

    for (int i = 0; i < n; i++) {
        int ch = s[i]-'0';
        if (i >= 1) {
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    pref[i][x][y] = pref[i-1][x][y];
                    if (y == ch) pref[i][x][y] += cnt[x];
                    pref[i][x][y] %= MOD;
                }
            }
        }
        cnt[ch]++;
    }

    lli suf[n][10][10]; memset(suf, 0, sizeof suf);
    cnt = vi(10);

    for (int i = n-1; i >= 0; i--) {
        int ch = s[i]-'0';
        if (i < n-1) {
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    suf[i][y][x] = suf[i+1][y][x];
                    if (y == ch) suf[i][y][x] += cnt[x];
                    suf[i][y][x] %= MOD; 
                }
            }
        }
        cnt[ch]++;
    }

    lli ans = 0;
    for (int i = 2; i < n-1; i++) {
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                (ans += pref[i-1][x][y] * suf[i+1][y][x] % MOD) % MOD;
            }
        }
    }
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
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}