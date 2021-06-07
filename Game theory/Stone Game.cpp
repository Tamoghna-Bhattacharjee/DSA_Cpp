#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ulli unsigned long long int
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back   
const lli INF = 1e18-1;

// https://codeforces.com/contest/1397/problem/D

void solve() {
   int n; cin >> n;
   priority_queue<int> pq;
   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      pq.push(x);
   }
   bool winner[] = {true, true};
   while (winner[0] && winner[1]) {
      if (pq.empty()) winner[0] = false;
      else {
         int x = pq.top(); pq.pop();
         x--;
         if (pq.empty()) winner[1] = false;
         else {
            int y = pq.top(); pq.pop();
            y--;
            if (x > 0) pq.push(x);
            if (y > 0) pq.push(y);
         }
      }
   }
   if (winner[0]) cout << "T\n";
   else cout << "HL\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; cin >> t;
   while (t--) solve();
}