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

// https://codeforces.com/contest/1398/problem/C

lli subArraySumEqK(int a[], int k, int n) {
   map<int, lli> cnt;
   cnt[0] = 1;
   lli res = 0, sum = 0;
   for (int i = 0; i < n; i++) {
      sum += a[i];
      if (cnt.find(sum - k) != cnt.end()) res += cnt[sum - k];
      cnt[sum-k]++;
   }
   return res;
}

void solve() {
   int n; cin >> n;
   string s; cin >> s;
   int a[n];
   for (int i = 0; i < n; i++) a[i] = s[i] - '0' - 1; 
   // subtracting 1 from every index so that so that sum(i, j) = 0 => actual sum = subarray length
   cout << subArraySumEqK(a, 0, n) << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; cin >> t;
   while (t--) solve();
}