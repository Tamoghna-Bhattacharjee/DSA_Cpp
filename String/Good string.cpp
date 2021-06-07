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

// https://codeforces.com/contest/1389/problem/C

void solve() {
    string s; cin >> s;
    int mx = 0;
    for (char i = '0'; i <= '9'; i++) {
        for (char j = '0'; j <= '9'; j++) {
            int cnt = 0;
            for (char ch: s) {
                if (cnt % 2 == 0 && ch == i) cnt++;
                else if (cnt % 2 == 1 && ch == j) cnt++;
            }
            if (i != j && cnt % 2 == 1) cnt--; 
            mx = max(mx, cnt);
        }
    }
    cout << s.size() - mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}