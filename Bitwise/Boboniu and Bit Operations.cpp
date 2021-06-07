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

// https://codeforces.com/contest/1395/problem/C

// if my ans is A then all ci | A = A  => (ai & bj) | A = A;

int solve() {
   int n, m; cin >> n >> m;
   int a[n], b[m];
   for (int i = 0; i < n; i++) cin >> a[i];
   for (int i = 0; i < m; i++) cin >> b[i];
   for (int ans = 0; ans <= 1 << 9; ans++) {
      bool ok = true;
      for (int i = 0; i < n && ok; i++) {
         ok = false;
         for (int j = 0; j < m && !ok; j++) {
            ok = ans == (ans | (a[i] & b[j]));
         }
      }
      if (ok) return ans;
   }
   return 0;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; 
   while (t--) cout << solve() << endl;
}