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

// https://codeforces.com/contest/1375/problem/D

void solve() {
    int n; cin >> n;
    int a[n];
    map<int, int> F;
    set<int> s;
    vi res;
    for (int i = 0; i <= n; i++) s.insert(i);
    for (int i = 0; i < n; i++) cin >> a[i], F[a[i]]++, s.erase(a[i]);
    while (s.size() > 1) {
        int x = *s.begin();
        s.erase(x);
        F[a[x]]--;
        if (F[a[x]] == 0) s.insert(a[x]);
        a[x] = x;
        res.pb(x);
    }
    while (true) {
        int j;
        for (j = 0; j < n; j++) {
            if (a[j] == j) continue;
            int x = *s.begin(); s.erase(x);
            if (x < n) s.insert(a[x]), a[x] = x, res.pb(x);
            else {
                s.insert(a[j]); a[j] = x; res.pb(j); break;
            }
        }
        bool isok = true;
        for (int i = 0; i < n && isok; i++) isok = a[i] == i;
        if (isok) break;
    }
    cout << res.size() << endl;
    for (int i: res) cout << (i+1) << " ";
    cout << endl;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}

