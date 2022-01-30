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
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1529/problem/D

int spf[N+1];

void pre() {
    for (int i = 0; i <= N; i++) spf[i] = i;
    for (int i = 2; i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i+i; j <= N; j+=i) spf[j] = min(spf[j], i);
        }
    }
}

lli cntDivisor(int n) {
    map<lli, lli> mp;
    while (n > 1) {
        mp[spf[n]]++;
        n /= spf[n];
    }
    lli res = 1;
    for (auto i: mp) res = res * (i.second + 1) % MOD;
    return res % MOD;
}

void solve() {
    pre();
    int n; cin >> n;
    vlli dp(n+1), pref(n+1);
    dp[0] = pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        // no. of even factors of 2*n = no. of factors of n
        dp[i] = (pref[i-1] + cntDivisor(i)) % MOD; 
        pref[i] = (pref[i-1] + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
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