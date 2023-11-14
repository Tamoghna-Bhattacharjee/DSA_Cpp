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

// https://www.interviewbit.com/problems/count-good-subsequences/

// A string/array is good if all its elements present in it have the same frequency
// given a string/array find the number of good subsequence.
// two subseq with same letters/numbers but having atleast one letter of diff index 
// is consider diff
// eg: [1,2,1,1] : both [2, 1(idx=3)] and [2,1(idx=4)] is considered diff

vlli F1, F2, inv;

void pre(int n) {
    //cout << n << endl;
    F1 = vlli(n+1); F2 = vlli(n+1);
    inv = vlli(n+1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
    }
    F1[0] = F2[0] = 1;
    for (int i = 1; i <= n; i++) {
        F1[i] = i * F1[i-1] % MOD;
        F2[i] = F2[i-1] * inv[i] % MOD;
    }
}

lli nCr(int n, int r) {
    if (r > n) return 0;
    return F1[n] % MOD * F2[r] % MOD * F2[n-r] % MOD;
}

lli power(lli a, lli n) {
    lli res = 1;
    while (n > 0) {
        if (n % 2) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

lli getCntGoodSubstrng(map<int, int> ff, int k) {
    lli p = 1;
    for (auto i: ff) {
        p = p * power((nCr(i.first, k) % MOD + 1) % MOD, i.second) % MOD;
    }
    p--;
    return p;
}

void solve() {
    int n; cin >> n;
    int a[n]; for (int &i: a) cin >> i;
    pre(n);
    map<int, int> f; // freq
    for (int i: a) f[i]++;
    map<int, int> ff;   // freq of freq
    for (auto i: f) ff[i.second]++;

    lli ans = 0;
    for (int k = 1; k <= n; k++) {
        ans += getCntGoodSubstrng(ff, k);
        ans = ans % MOD;
    }
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
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}