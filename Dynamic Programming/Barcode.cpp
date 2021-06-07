#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
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

// https://codeforces.com/problemset/problem/225/C

void solve() {
    int n, m, x, y; 
    cin >> n >> m >> x >> y;
    lli pref[2][m+1], dp[2][m+1]; 
    memset(pref, 0, sizeof pref);
    
    // 0 -> '.'    1 -> '#'
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if(s[j] == '#') pref[1][j+1]++;
            else pref[0][j+1]++; 
        }
    }
    for (int i = 1; i <= m; i++) pref[0][i] += pref[0][i-1], pref[1][i] += pref[1][i-1];
    for (int i = 0; i <= m; i++) dp[0][i] = dp[1][i] = INT_MAX;

    for (int i = 0; i <= m; i++) dp[0][i] = dp[1][i] = INT_MAX;
    dp[0][0] = dp[1][0] = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = i-y; j <= i-x; j++) {
            if (j >= 0) {
                dp[0][i] = min(dp[0][i], dp[1][j] + pref[0][i]-pref[0][j]);
                dp[1][i] = min(dp[1][i], dp[0][j] + pref[1][i]-pref[1][j]);
            }
        }
    }
    cout << min(dp[0][m], dp[1][m]) << endl;
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