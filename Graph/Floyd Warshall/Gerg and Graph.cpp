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
const int N = 1e7;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/295/problem/B

void solve() {
    int n; cin >> n;
    lli dp[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> dp[i][j];
    }
    int x[n+1];
    for (int i = 1; i <= n; i++) cin >> x[i];
    reverse(x+1, x+n+1);
    vlli res;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[x[i]][x[k]] == INF || dp[x[k]][x[j]] == INF) continue;
                dp[x[i]][x[j]] = min(dp[x[i]][x[j]], dp[x[i]][x[k]] + dp[x[k]][x[j]]);
            }
        }
        lli sum = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) sum += dp[x[i]][x[j]];
        }
        res.pb(sum);
    }
    reverse(res.begin(), res.end());
    debug(res);
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