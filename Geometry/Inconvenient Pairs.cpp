#include <bits/stdc++.h>
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

const lli INF = 1e18, MOD = 998244353;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1569/problem/D

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi v(n), h(m);
    for (int &i: v) cin >> i;
    for (int &i: h) cin >> i;
    v.pb(INT_MAX); h.pb(INT_MAX);

    map<pair<int, int>, map<int, int>> mph, mpv;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        auto itx = lower_bound(v.begin(), v.end(), x);
        auto ity = lower_bound(h.begin(), h.end(), y);
        if (*itx == x && *ity == y) continue;
        if (*ity == y) mph[{*prev(itx), *itx}][y]++;
        else if (*itx == x) mpv[{*prev(ity), *ity}][x]++;
    }
    lli ans = 0;
    for (auto i: mph) {
        lli cnt = 0;
        for (auto j: i.second) {
            lli t = j.second;
            cnt += t;
            ans -= t*(t-1)/2;
        }
        ans += cnt * (cnt - 1) / 2;
    }
    for (auto i: mpv) {
        lli cnt = 0;
        for (auto j: i.second) {
            lli t = j.second;
            cnt += t;
            ans -= t*(t-1)/2;
        }
        ans += cnt * (cnt - 1) / 2;
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
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}