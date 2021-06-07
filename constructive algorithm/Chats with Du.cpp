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

// https://codeforces.com/contest/1395/problem/D

void solve() {
   lli n, d, m; cin >> n >> d >> m;
   lli a[n];
   vector<lli> g, l;
   for (int i = 0; i < n; i++) cin >> a[i];
   for (lli i: a) {
      if (i > m) g.pb(i);
      else l.pb(i);
   }
   sort(g.begin(), g.end(), greater<lli>());
   sort(l.begin(), l.end(), greater<lli>());
   for (int i = 1; i < l.size(); i++) l[i] += l[i-1];
   for (int i = 1; i < g.size(); i++) g[i] += g[i-1];
   l.insert(l.begin(), 0);
   lli res = 0;
   
   if (g.empty()) res = l.back();
   else {
      for (int i = 0; i < (int) g.size(); i++) {
         lli ind = i*(d+1) + 1;
         if (ind <= n) res = max(res, g[i] + l[min((lli) l.size() - 1, n-ind)]);
      }
   }
   cout << res << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; 
   while (t--) solve();
}