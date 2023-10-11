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

const lli INF = 1e13, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://codeforces.com/contest/1811/problem/E
// https://www.geeksforgeeks.org/count-numbers-from-1-to-n-that-have-4-as-a-a-digit/

/* Alternate way

int dp[10][2];

int f(string &s, int i, bool tight, int power) {
    if (i >= s.size()) return 0;
    if (dp[i][tight] != -1) return dp[i][tight];
    int ans = 0;
    int end = tight? s[i]-'0': 9;
    for (int j = 0; j <= end; j++) {
        if (j == 4) {
            if (j != end) ans += power;
            else ans += atoi(s.c_str()) % power + 1;
        } else {
            ans += f(s, i+1, tight & (j == end), power/10);
        }
    }
    return dp[i][tight] = ans;
}

int countNumberswith4(int N) {
    memset(dp, -1, sizeof dp);
    string s = to_string(N);
    int p = 1;
    for (int i = 0; i < s.size()-1; i++) p*=10;
    return f(s, 0, 1, p);
}

*/

vlli cnt(19), p(19);

void pre() {
    // computing count of numbers with 4 in it from 1 to 10^d-1,
    // d=0 cnt[0] = 0;
    // d=1 cnt[1] = count of numbers from 1 to 9 = 1
    // d=2 cnt[2] = count of numbers from 1 to 99 = cnt[1]*9 + 10 = 19
    // d=3 cnt[3] = count of numbers from 1 to 999 = cnt[2]*9 + 100 = 271
    p[0] = 1;
    for (int i = 1; i <= 18; i++) {
        cnt[i] = 9 * cnt[i-1] + p[i-1];
        p[i] = p[i-1] * 10;
    }
}

lli countNumbersWith_K(lli n, lli digit) {
    if (n < 4) return 0;
    if (n < 10) return 1;
    lli d = log10(n);
    lli msd = n/p[d];
    if (msd == digit) return msd * cnt[d] + n % p[d] + 1;
    else if (msd > digit) return (msd-1)*cnt[d] + p[d] + countNumbersWith_K(n%p[d], digit);
    else return (msd)*cnt[d] + countNumbersWith_K(n%p[d], digit);
}

void solve() {
    lli k; cin >> k;
    lli L = 1, R = INF, ans = -1;
    while (L <= R) {
        lli mid = (L + R) / 2;
        if (mid - countNumbersWith_K(mid, 4) >= k) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
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
    int t = 1; cin >> t; pre();
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}