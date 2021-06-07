#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1359/problem/C

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    lli ans = 0;
    if (2*t == h+c) ans = 2;
    else {
        lli x1 = ceil(((double) (t-c))/(2*t-h-c)), x2 = floor(((double) (t-c))/(2*t-h-c));
        
        if ((x1 > 0) && (x2 > 0)) {
            double tb1 = ((double) (x1*(h+c) - c)) / (2*x1-1);
            double tb2 = ((double) (x2*(h+c) - c)) / (2*x2-1);
            double d1 = fabs(tb1 - t), d2 = fabs(tb2 - t);
            if (d1 < d2) ans = 2*x1 - 1;
            else ans = 2*x2 - 1; 
        }
        else if ((x1 < 0) && (x2 < 0)) ans = 2;
        else if (x1 < 0) ans = max(2*x2-1, (lli) 2);
        else ans = max(2*x1-1, (lli)2); 
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
