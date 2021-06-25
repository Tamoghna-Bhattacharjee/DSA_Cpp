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

const lli INF = 1e18-1, MOD = 998244353;
const int N = 150000; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1433/problem/F

int a[72][72], dp[72][72][72][72];
int n, m, k;

int f(int i, int j, int cnt, int rem) {
    if (i >= n) {
        if (rem == 0) return 0;
        return -1e9;
    }
    int x = -1e9, y = -1e9;
    if(dp[i][j][cnt][rem] != -1) return dp[i][j][cnt][rem];
        
    if (j == m) x = f (i+1, 0, 0, rem);
    else {
        x = f (i, j+1, cnt, rem);
        if (cnt < m/2) y = f(i, j+1, cnt+1, (rem + a[i][j]) % k) + a[i][j];
    }
    return dp[i][j][cnt][rem] = max(x, y);
}

void solve () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    memset(dp, -1, sizeof(dp)); 
    cout << f(0,0,0,0) << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}