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

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 80;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);


lli F1[N+1], F2[N+1], inv[N+1];

// dp[i][j][k] = #ways to have sum == k by taking j elements out of i+1
vector<vector<vlli>> dp; 
int n, m, tot;

void pre() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (MOD - (MOD/i * inv[MOD % i] % MOD) % MOD) % MOD;
    }
    F1[0] = F2[0] = 1;
    for (lli i = 1; i <= N; i++) {
        F1[i] = F1[i-1] * i % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli f(int i, int cnt, int sum, string &s) {
    if (i >= n) return cnt == m && 2*sum == tot;
    if (sum > tot/2 || cnt > m) return 0;
    if (dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
    lli ans = (f(i+1, cnt, sum, s) + f(i+1, cnt+1, sum + (s[i]-'0'), s)) % MOD;
    return dp[i][cnt][sum] = ans;
}

void solve() {
    string s; cin >> s;
    n = s.size(); m = n/2;

    vector<int> freq(10);
    tot = 0;
    for (char i: s) {
        freq[i-'0']++;
        tot += i-'0';
    }

    if (tot % 2) {
        cout << 0 << endl;
        return;
    }

    dp = vector<vector<vlli>>(n+1, vector<vlli>(m+1, vlli((tot/2)+1, -1)));
    lli res = f(0, 0, 0, s) % MOD;
    res = res * F1[m] % MOD * F1[n-m] % MOD;
    for (int i: freq) res = res * F2[i] % MOD;
    cout << res << endl;
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