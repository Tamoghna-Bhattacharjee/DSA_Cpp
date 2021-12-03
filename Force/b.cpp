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

const lli INF = 1e18, MOD = 998244353;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

lli n;
vlli a, dp;

lli power(lli a, lli m) {
    lli res = 1;
    while (m > 0) {
        if (m%2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        m /= 2;
    }
    return res;
}

void solve() {
    cin >> n;
    a = vlli(n); for (lli &i: a) cin >> i;
    map<lli, lli> F;
    for (lli i: a) F[i]++;
    // dp = vlli(n+1);
    // dp[0] = F[0];
    // for (int i = 1; i <= n; i++) dp[i] = dp[i-1] + F[i];
    if (n == 1) {
        cout << (a[0] <= 1) << endl;
        return;
    }
    // lli cnt = dp[2] - F[1];
    lli ans = (power(2, F[0]+F[2]) % MOD + MOD - 1) % MOD;
    ans = (ans + MOD + power(2, F[1]) % MOD - 1) % MOD;
    cout << ans << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}