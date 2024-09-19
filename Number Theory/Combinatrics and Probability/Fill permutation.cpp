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
#define all(__x) __x.begin(),__x.end()

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
const double PI = acos(-1);

// https://www.codechef.com/problems/FILLIN0?tab=statement

/*
    Intutition - Consider the permutaion of length 2N is empty
    Max sum that can be achived - (2N) + (2N-1) + ... + (N+1)
                                    - (1 + 2 + ... + N)
    So for 1 we can pair it with (N+1), N+2, ..., 2N --> N num
       for 2 we can pair N-1 num (because one of [N+1, 2N] is taken by 1)
       ....
       So total arrangement is N!

       1 to N can be arranged in another N! * 2^N ways

       total ways = N! * N! * (2^N)

actual ans = (N-less already taken)! * (N-greater already taken)! * 2 ^ (0 0 pair cnt)
*/  

lli F1[N+1], F2[N+1], inv[N+1];

void pre() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (MOD - MOD/i*inv[MOD%i]%MOD) % MOD;
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= N; i++) {
        F1[i] = i * F1[i-1] % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli ncr(int n, int r) {
    if (n < r) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
}

lli power(lli a, lli n) {
    lli res = 1;
    while (n) {
        if (n % 2) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vi p(2*n+1); for (int i = 1; i <= 2*n; i++) cin >> p[i];

    int less = 0, great = 0, cnt = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (p[i] != 0 && p[i] <= n) less++;
        if (p[i] != 0 && p[i] > n) great++;
    }

    for (int i = 1; i <= 2*n; i+=2) {
        if (i+1 <= 2*n && p[i] == 0 && p[i+1] == 0) cnt++;
    }

    lli ans = F1[n-less] % MOD * F1[n-great] % MOD * power(2, cnt) % MOD;
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