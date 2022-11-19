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

// https://codeforces.com/contest/993/problem/E

struct Complex {
    double a, b;
    Complex(double a = 0, double b = 0) : a(a), b(b) {}
    Complex operator+ (const Complex c) const {
        return Complex(a + c.a, b + c.b);
    }
    Complex operator- (const Complex c) const {
        return Complex(a-c.a, b-c.b);
    }
    Complex operator* (const Complex c) const {
        return Complex(a * c.a - b * c.b, a * c.b + b * c.a);
    }
};

void fft(vector<Complex> &a, bool inv) {
    int sz = a.size();
    if (sz == 1) return;
    vector<Complex> a_even, a_odd;
    for (int i = 0; i < sz; i++) {
        if (i%2) a_odd.pb(a[i]);
        else a_even.pb(a[i]);
    }
    fft(a_even, inv);
    fft(a_odd, inv);
    double ang = (2 * PI / sz) * (inv ? -1: 1);
    Complex w(1), wn(cos(ang), sin(ang));

    for (int i = 0; 2 * i < sz; i++) {
        a[i] = a_even[i] + w * a_odd[i];
        a[i + sz/2] = a_even[i] - w * a_odd[i];
        w = w * wn;
    }
    if (inv) {
        for (int i = 0; i < sz; i++) {
            a[i].a /= 2; a[i].b /= 2;
        }
    }
}

vlli multiply(vlli &a, vlli &b) {
    vector<Complex> ca(a.begin(), a.end()), cb(b.begin(), b.end());
    lli sz = 1;
    while (sz < a.size() + b.size()) sz <<= 1;
    ca.resize(sz); cb.resize(sz);
    fft(ca, false);
    fft(cb, false);
    vector<Complex> ans;
    for (int i = 0; i < sz; i++) ans.pb(ca[i]*cb[i]);
    fft(ans, true);
    vlli res;
    for (auto &i: ans) res.pb(round(i.a));
    return res;
}

void solve() {
    lli n, x; cin >> n >> x;
    vlli a(n), in(n);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        in[i] = a[i] < x; 
        if (i-1 >= 0) in[i] += in[i-1];
    }
    vlli cnt(n+1), rev;
    cnt[0] = 1;
    for (lli i: in) cnt[i]++;
    rev = cnt; reverse(rev.begin(), rev.end());
    vlli res = multiply(cnt, rev);
    vlli ans(n+1);
    for (lli i: cnt) ans[0] += i * (i-1) / 2;
    for (int i = 1; i <= n; i++) ans[i] = res[n+i];
    debug(ans);
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