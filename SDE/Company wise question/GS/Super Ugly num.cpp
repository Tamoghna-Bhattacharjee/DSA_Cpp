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

void uglyNum2() {
    // https://leetcode.com/problems/ugly-number-ii/

    int n; cin >> n;
    vector<int> dp(n+1); dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = min({2*dp[p2], 3*dp[p3], 5*dp[p5]});
        if (dp[i] == 2*dp[p2]) ++p2;
        if (dp[i] == 3*dp[p3]) ++p3;
        if (dp[i] == 5*dp[p5]) ++p5;
    }
    cout << dp[n] << endl;
}


// https://leetcode.com/problems/super-ugly-number/

void solve() {
    int n, m; cin >> n >> m; // n --> find nth ugly num,    m -> size of prime
    vi primes(m); for (auto &i: primes) cin >> i;
    vector<int> dp(n+1);
    dp[1] = 1;

    // pq[x] -> val, prime, prime multiplied by which last ugly number
    priority_queue<pair<lli, pair<lli, lli>>> pq;  
    for (int i: primes) pq.push({-i, {i, 1}});

    set<lli> s; s.insert(1);
    while (dp[n] == 0) {
        auto cur = pq.top(); pq.pop();
        lli val = -cur.first, p = cur.second.first, idx = cur.second.second;
        s.insert(val);
        dp[s.size()] = val;
        pq.push({-p * dp[idx+1], {p, idx+1}});
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
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}