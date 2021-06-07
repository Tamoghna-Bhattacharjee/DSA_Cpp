#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back   
const lli INF = 1e18;

// https://codeforces.com/contest/1393/problem/D

const int N = 2005;
int L[N][N], R[N][N], up[N][N], down[N][N];
char s[N][N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= n; i++)   
        for (int j = 1; j <= m; j++) up[i][j] = s[i][j] == s[i-1][j]? up[i-1][j]+1 :1;
    for (int i = n; i >= 1; i--) 
        for (int j = 1; j <= m; j++) down[i][j] = s[i][j] == s[i+1][j]? down[i+1][j]+1: 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            L[i][j] = s[i][j] == s[i][j-1]? min(min(up[i][j], down[i][j]), L[i][j-1]+1) :1;
    for (int i = 1; i <= n; i++) 
        for (int j = m; j >= 1; j--) 
            R[i][j] = s[i][j] == s[i][j+1]? min(min(up[i][j], down[i][j]), R[i][j+1]+1): 1;
    lli ans = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            ans += min(L[i][j], R[i][j]);
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    while (t--) solve();
}