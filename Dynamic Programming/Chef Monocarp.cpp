#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e9, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1437/problem/C

int n, t[205];
lli dp[205][500];

lli f(int i, int T) {
    if (i > n) return 0;
    if (T > 2*n) return INF;
    if (dp[i][T] != -1) return dp[i][T];
    return dp[i][T] = min(f(i, T+1), abs(T - t[i]) + f(i+1, T+1));
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i = 0; i <= n; i++)   
        for (int j = 0; j <= 500; j++) dp[i][j] = -1;
    cout << f(1,1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}