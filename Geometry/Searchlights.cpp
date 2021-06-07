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
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) cout << i << " "; cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 1e6;  

// https://codeforces.com/contest/1408/problem/D

void solve() {
    int n, m, x, y; cin >> n >> m;
    vpii robber, light;
    for (int i = 0; i < n; i++) cin >> x >> y, robber.pb({x, y});
    for (int i = 0; i < m; i++) cin >> x >> y, light.pb({x, y});
    vi arr(N+1);
    for (auto i: robber) {
        for (auto j: light) {
            if (i.first <= j.first && i.second <= j.second) {
                int dx = j.first - i.first;
                int dy = j.second - i.second + 1;
                arr[dx] = max(arr[dx], dy);
            }
        }
    }
    
    for (int i = N-1; i >= 0; i--) arr[i] = max(arr[i], arr[i+1]);
    int ans = INT_MAX;
    for (int i = 0; i <= N; i++) ans = min(ans, i+arr[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}