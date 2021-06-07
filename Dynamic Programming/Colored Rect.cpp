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
const lli INF = 1e18-1;

// https://codeforces.com/contest/1398/problem/D

lli dp[201][201][201], R[201], G[201], B[201];

lli f(int i, int j, int k) {
   if (dp[i][j][k] != -1) return dp[i][j][k];
   dp[i][j][k] = 0;
   lli x = -INF, y = -INF, z = -INF;
   if (i-1 >= 0 && j-1 >= 0) x = R[i-1] * G[j-1] + f(i-1, j-1, k);
   if (i-1 >= 0 && k-1 >= 0) y = R[i-1] * B[k-1] + f(i-1, j, k-1);
   if (j-1 >= 0 && k-1 >= 0) z = G[j-1] * B[k-1] + f(i, j-1, k-1);
   dp[i][j][k] = max(x, max(y, z));
   return dp[i][j][k];
}

void solve() {
   int r, g, b; cin >> r >> g >> b;
   for (int i = 0; i < r; i++) cin >> R[i];
   for (int i = 0; i < g; i++) cin >> G[i];
   for (int i = 0; i < b; i++) cin >> B[i];
   sort(R, R+r); sort(G, G+g); sort(B, B+b);
   for (int i = 0; i <= r; i++) 
      for (int j = 0; j <= g; j++) 
         for (int k = 0; k <= b; k++) dp[i][j][k] = -1;
   
   for (int i = 0; i < 201; i++) dp[i][0][0] = dp[0][i][0] = dp[0][0][i] = 0;
   
   cout << f(r, g, b) << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; 
   while (t--) solve();
}