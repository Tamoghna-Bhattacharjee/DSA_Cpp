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

// https://codeforces.com/contest/1384/problem/B2

void solve() {
    int n, k, l; cin >> n >> k >> l;
    vi safe;
    int d[n+1];
    safe.pb(0);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] + k <= l) safe.pb(i);
    }
    safe.pb(n+1);
    bool ok = true;
    for (int i = 1; i < safe.size() && ok; i++) {
        int tide = k;
        bool down = true;
        for (int j = safe[i-1]+1; j < safe[i] && ok; j++) {
            tide += down? -1: 1;
            if (down) {
                if (d[j] + tide > l) tide -= d[j] + tide - l;
                if (tide < 0) ok = false;
            } else ok = d[j] + tide <= l;
            if (tide == 0) down = false;
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}