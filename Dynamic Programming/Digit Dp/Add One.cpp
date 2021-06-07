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
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

lli dp[10][N+1]; // dp[i][j] = length of digit i after j moves

void pre() {
    for (int i = 0; i < 10; i++) dp[i][0] = 1;
    for (int moves = 1; moves <= N; moves++) {
        for (int digit = 0; digit <= 8; digit++) {
            dp[digit][moves] = dp[digit+1][moves-1];
        }
        dp[9][moves] = (dp[0][moves-1] + dp[1][moves-1]) % MOD;
    }
}

void solve() {
    string s; cin >> s;
    int m; cin >> m;
    lli ans = 0;
    for (char i: s) {
        ans = (ans + dp[i-'0'][m]) % MOD;
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
    //cout << fixed << setprecision(9);
    pre();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}