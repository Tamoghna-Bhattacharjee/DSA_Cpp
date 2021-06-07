#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e9-1, MOD = 998244353;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1462/problem/F

void solve () {
    int n; cin >> n; 
    vpii seg;
    vi L, R;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        seg.pb({l, r});
        L.pb(l); R.pb(r);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans = INT_MAX;
    for (auto i: seg) {
        int l = i.first, r = i.second;
        int Lgr = L.end() - upper_bound(L.begin(), L.end(), r); // r < L;
        int Rll = lower_bound(R.begin(), R.end(), l) - R.begin();
        ans = min(ans, Lgr + Rll);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    while (t--) solve();
}