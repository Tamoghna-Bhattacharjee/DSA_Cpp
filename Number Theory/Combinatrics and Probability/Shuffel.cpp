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

// https://codeforces.com/contest/1622/problem/D

vlli F1, F2, inv;

void pre(int n) {
    F1 = vlli(n+1); F2 = vlli(n+1); inv = vlli(n+1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD/i * inv[MOD%i] % MOD) % MOD;
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

bool check(string s, int k) {
    int cnt = 0;
    for (char i: s) cnt += i-'0';
    return cnt < k;
}

void solve() {
    int n, k; cin >> n >> k;
    pre(n);
    string s; cin >> s;
    if (k == 0 || check(s,k)) {
        cout << 1 << endl;
        return;
    }
    lli ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt[2] = {0,0};
        for (int j = i; j < n; j++) {
            cnt[s[j]-'0']++;
            if (cnt[1] > k) break;
            int c[] = {cnt[0], cnt[1]};
            c[1 ^ (s[i]-'0')]--; c[1 ^ (s[j]-'0')]--;
            if (c[0] >= 0 && c[1] >= 0) {
                ans = (ans + nCr(c[0]+c[1], c[1]) % MOD) % MOD;
            } 
        }
    }
    ans = (ans + 1) % MOD;
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