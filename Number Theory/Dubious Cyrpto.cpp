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

// https://codeforces.com/contest/1379/problem/B

void solve() {
    lli l, r, m; cin >> l >> r >> m;
    lli a, b, c, n;
    if (m >= l) {
        lli d = r-l;
        lli r1 = m+d;
        for (lli i = l; i <= r; i++) {
            lli x = r1/i;
            if (abs(m - x*i) <= d) {
                a = i, n = x; break;
            }
        }
        d = m - n*a;
        if (d < 0) c = r; 
        else c = l;
        b = c+d;
    } else {
        a = l; 
        lli d = m-a;
        b = l; c = b+abs(d); n = 1;
    }
    /*string s;
    if (n*a+b-c == m && b >= l && b <= r && c >= l && c <= r) s = "OK\n";
    else s = "WRONG\n";
    cout << "ans = " << a << " " << b << " " << c << " " << n << " " << s;*/
    cout << a << " " << b << " " << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}

