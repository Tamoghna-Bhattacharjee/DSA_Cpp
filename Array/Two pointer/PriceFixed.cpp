#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};  

// https://codeforces.com/contest/1539/problem/D

void solve() {
    int n; cin >> n;
    pair<lli, lli> p[n];
    for (int i = 0; i < n; i++) {
        lli a, b; cin >> a >> b;
        p[i] = {b,a};
    }
    sort(p,p+n);
    int L = 0, R = n-1;
    lli ans = 0, buy = 0;
    while (L <= R) {
        if (p[L].first <= buy) {
            buy += p[L].second;
            ans += p[L].second;
            L++;
        } else {
            lli x = min(p[L].first - buy, p[R].second);
            p[R].second -= x;
            ans += x*2;
            buy += x;
            if (p[R].second == 0) R--;
        }
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