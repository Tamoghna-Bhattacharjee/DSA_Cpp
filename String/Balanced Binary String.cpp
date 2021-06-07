#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back   
const lli INF = 1e18-1, MOD = 1000000007;
const int N = 1e5;

// https://codeforces.com/contest/1405/problem/C

void solve() {
   int n, k; cin >> n >> k;
   string s; cin >> s;
   bool ok = true;
   for (int i = 0; i < k && ok; i++) {
      bool one = false, zero = false, qs = false;
      for (int j = i; j < n; j += k) {
         if (s[j] == '1') one = true;
         if (s[j] == '0') zero = true;
         if (s[j] == '?') qs = true;
      }
      if (one && zero) {
         ok = false;
      } else {
         if (one) {
            for (int j = i; j < n; j += k) s[j] = '1';
         } else if (zero) {
            for (int j = i; j < n; j += k) s[j] = '0';
         }
      }
   }

   if (ok) {
      int one = 0, zero = 0, qs = 0;
      for (int i = 0; i < k; i++) {
         one += s[i] == '1';
         zero += s[i] == '0';
         qs += s[i] == '?';
      }
      if (qs == 0) ok = one == zero;
      else {
         qs -= abs(one - zero);
         ok = qs % 2 == 0 && qs >= 0;
      }
   }
   if (ok) cout << "YES\n";
   else cout << "NO\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; cin >> t;
   while (t--) solve();
}