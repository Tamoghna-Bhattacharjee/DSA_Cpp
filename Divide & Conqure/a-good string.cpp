#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1385/problem/D

string s;

int f(int L, int R, char ch) {
    if (L > R) return 0;
    if (L == R) return s[L] != ch;
    int cnt1 = 0, cnt2 = 0;
    int mid = (L + R) / 2;
    for (int i = L; i <= mid; i++) cnt1 += s[i] != ch;
    for (int i = mid+1; i <= R; i++) cnt2 += s[i] != ch;
    ch++;
    return min(cnt1 + f(mid+1, R, ch), cnt2 + f(L, mid, ch));
}

int solve() {
    int n; cin >> n;
    cin >> s;
    return f(0, n-1, 'a');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) cout << solve() << endl;
}
