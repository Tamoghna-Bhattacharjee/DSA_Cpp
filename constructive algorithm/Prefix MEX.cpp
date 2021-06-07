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

// https://codeforces.com/contest/1364/problem/C

void solve() {
    int n; cin >> n;
    int arr[n], res[n], mx = 0;
    si s;
    for (int i = 0; i <= max(n, mx) + 1; i++) s.insert(i);

    for (int i = 0; i < n; i++) cin >> arr[i], mx = max(mx, arr[i]), s.erase(arr[i]);
    bool isok = true;
    for (int i = 1; i < n && isok; i++) isok = arr[i] >= arr[i-1];
    if (!isok) {
        cout << -1 << endl; return;
    }
    for (int i = 0; i < n; i++) {
        s.erase(arr[i]);
        res[i] = *s.begin();
        s.erase(res[i]);
        s.insert(arr[i]);
    }
    for (int i: res) cout << i << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1;
    while (t--) solve();
}

