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

// https://codeforces.com/contest/1374/problem/C

void solve() {
    int n; 
    string s;
    cin >> n >> s;
    int op = 0, b = 0;
    for (char i: s) {
        if (i == ')') b--;
        else b++;
        if (b < 0) op++, b = 0;
    }
    cout << op << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
    