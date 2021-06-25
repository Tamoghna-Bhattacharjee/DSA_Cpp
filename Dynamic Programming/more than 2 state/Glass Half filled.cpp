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
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1459/problem/D

int n, a[101], b[101];
int dp[101][101][11000];

void solve() {
    cin >> n;
    int A = 0, B = 0;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], A += a[i], B += b[i];
    
    for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100; j++)
    for (int k = 0; k <= A; k++) dp[i][j][k] = INT_MIN;
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            for (int sa = 0; sa <= 10000; sa++) {
                dp[i][k][sa] = dp[i-1][k][sa];
                if (k >= 1 && sa >= a[i]) dp[i][k][sa] = max(dp[i-1][k][sa], dp[i-1][k-1][sa - a[i]] + b[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int sa = 1; sa <= A; sa++) {
            ans = max(ans, min(2*sa, dp[n][i][sa] + B));
        }
        double res = 0.5 * ans;
        cout << res << " ";
    }
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
    for (int i = 1; i <= t; i++) solve();
}