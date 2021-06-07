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

// https://codeforces.com/contest/1368/problem/C

void printBlk(int i, int j) {
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (k == 0 && l == 0) continue;
            if (k == 1 && l == 1) continue;
            cout << (i+k) << " " << (j+l) << endl;
        }
    }
}

void solve() {
    int n; cin >> n;
    lli total = 9*(n+1) - (n+1) - n;
    cout << total << endl;
    int i = 0, j = 0;
    cout << i << " " << j << endl;
    printBlk(i, j);
    while (n--) {
        i += 2; j += 2;
        printBlk(i, j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;
    while (t--) solve();
}
