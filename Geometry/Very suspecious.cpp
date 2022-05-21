#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

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
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1670/problem/D

vlli cnt, dp;

void pre() {
    cnt.pb(0); dp.pb(0);
    cnt.pb(0); dp.pb(0);
    cnt.pb(1); dp.pb(2);
    cnt.pb(2); dp.pb(2*2 + dp[2]);
    for (int i = 4; i <= N; i++) {
        if (i % 3 == 1) cnt.pb(cnt[i-1]);
        else cnt.pb(cnt[i-1] + 1);
        dp.pb(dp[i-1] + 2 * cnt[i]);
        if (dp.back() > (lli) 1e9) break;
    }
}

void solve() {
    lli n; cin >> n;
    cout << lower_bound(dp.begin(), dp.end(), n) - dp.begin() << endl;
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
    pre();
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}