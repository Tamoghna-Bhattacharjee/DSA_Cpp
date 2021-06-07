#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back  
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}
void debug(int _a) {cout << _a << " ";}

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 1e5;  
int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1427/problem/C

int timeDif(vi &a, vi &b) {
    // a > b interms of index
    return abs(a[2] - b[2]);
}
int dist(vi &a, vi &b) {
    return abs(b[0] - a[0]) + abs(b[1] - a[1]);
}

void solve() {
    int r, n; cin >> r >> n;
    vi dp(n+1), sufMax(n+1);
    vector<vi> p;
    p.pb({1,1,0});
    for (int i = 0; i < n; i++) {
        int t, x, y; cin >> t >> x >> y;
        p.pb({x, y, t});
    }
    if (dist(p[0], p[n]) <= timeDif(p[0], p[n])) dp[n] = sufMax[n] = 1;
    
    for (int i = n-1; i >= 1; i--) {
        int cnt = 0, j = i+1;
        while (j <= n) {
            if (timeDif(p[j], p[i]) > 2*r) break;
            if (dist(p[j], p[i]) <= timeDif(p[j], p[i])) cnt = max(cnt, dp[j]);
            j++;
        } 
        if (j <= n) cnt = max(cnt, sufMax[j]);
        dp[i] = 1 + cnt;
        sufMax[i] = max(sufMax[i+1], dp[i]);
        if (dist(p[0], p[i]) > timeDif(p[0], p[i])) dp[i] = 0;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}