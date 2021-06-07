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

// https://www.codechef.com/LTIME85B/problems/MAXAND18

bool cmp(const pair<lli, int> &x, const pair<lli, int> &y) {
	if (x.first != y.first)
		return x.first > y.first;

	return x.second < y.second;
}

void solve() {
	int n, k; cin >> n >> k;
    lli arr[n], B[30];
    memset(B, 0, 8*30);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (lli i: arr) {
        for (int j = 0; j < 30; j++) {
            lli F = 1 << j;
            if ((i & F) != 0) B[j]++;
        }
    }
    vector<pair<lli, int>> p;
    for (int i = 0; i < 30; i++) {
        lli x = B[i] * (1 << i);
        p.pb({x, i});
    }
    sort(p.begin(), p.end(), cmp);
    lli x = 0;
    for (int i = 0; i < k; i++) {
        x += 1 << p[i].second;
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
    