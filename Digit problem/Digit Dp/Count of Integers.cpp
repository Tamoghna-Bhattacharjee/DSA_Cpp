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

// https://leetcode.com/problems/count-of-integers/description/

lli dp[23][404][2];

lli digitDp_Util(string &s, int i, int sum, int tight) {
   if (i >= s.size()) return sum == 0;
   if (sum < 0) return 0;
   if (dp[i][sum][tight] != -1) return dp[i][sum][tight];
   lli ans = 0;
   int end = tight ? s[i] - '0' : 9;
   for (int j = 0; j <= end; j++) {
       ans += digitDp_Util(s, i + 1, sum - j, (tight & (j == end)));
       ans = ans % MOD;
   }
   return dp[i][sum][tight] = ans;
}

lli getForAllSum(string s, int min_sum, int max_sum) {
    lli ans = 0;
    memset(dp, -1, sizeof dp);
    for (int sum = min_sum; sum <= max_sum; sum++) {
        ans += digitDp_Util(s, 0, sum, 1);
        ans = ans % MOD;
    }
    return ans;
}

int count(string L, string R, int min_sum, int max_sum) {
    lli x = getForAllSum(R, min_sum, max_sum);
    lli y = getForAllSum(L, min_sum, max_sum);
    int sum = 0;
    for (char i: L) sum += i-'0';
    return (x-y+(min_sum <= sum && sum <= max_sum) + MOD) % MOD;
}

void solve() {
    string L, R; cin >> L >> R;
    int mi, mx; cin >> mi >> mx;
    cout << count(L,R,mi,mx) << endl;
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