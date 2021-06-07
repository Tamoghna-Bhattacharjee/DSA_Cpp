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

// https://codeforces.com/contest/1364/problem/B

void solve() {
    int n; cin >> n;
    int p[n]; 
    for (int i = 0; i < n; i++) cin >> p[i];
    vi res;
    res.pb(p[0]); res.pb(p[1]);
    for (int i = 2; i < n; i++) {
        int d1 = abs(p[i] - res[res.size()-1]) + abs(res[res.size()-1] - res[res.size()-2]);
        int d2 = abs(p[i] - res[res.size()-2]);
        if (d2 >= d1) res[res.size()-1] = p[i];
        else res.pb(p[i]);
    }
    cout << res.size() << endl;
    for (int i: res) cout << i << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}

