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

const lli INF = 1e18, MOD = 1e8;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = "#" + s;
    lli dp[n+1][2]; memset(dp, 0, sizeof dp);
    lli qs[n+1]; memset(qs, 0, sizeof qs);
    
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') dp[i][0] = dp[i-1][1]+1;
        else if (s[i] == '1') dp[i][1] = dp[i-1][0] + 1;
        else {
            dp[i][0] = dp[i-1][1]+1;
            dp[i][1] = dp[i-1][0]+1;
            if (s[i] == '?') qs[i] = qs[i-1]+1;
        }
    }
    lli sum = 0;
    for (int i = 1; i <= n; i++) sum += dp[i][0] + dp[i][1] - qs[i];
    cout << sum << endl;
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