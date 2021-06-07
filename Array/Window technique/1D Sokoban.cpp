#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 500;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1494/problem/C

int f(vi a, vi b) {
    
    int n = (int) a.size(), m = (int) b.size();
    vi suf(n+5);
    int r = m-1;
    for (int i = n-1; i >= 0; i--) {
        suf[i] = suf[i+1];
        while (r >= 0 && b[r] > a[i]) r--;
        if (r >= 0 && b[r] == a[i]) suf[i]++;
    }
    int ans = 0;
    int i = 0, R = 0;
    for (int L = 0; L < m; L++) {
        while (i < n && a[i] <= b[L] + i) i++;
        while (R < m && b[R] - b[L] + 1 <= i) R++;
        ans = max(ans, R - L + suf[i]);
    }
    return ans;
    return 0;
}

void solve() {
    int n, m; cin >> n >> m;
    vi a1, a2, b1, b2;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x >= 0) a1.pb(x);
        else a2.pb(-x);
    }
    reverse(a2.begin(), a2.end());
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (x >= 0) b1.pb(x);
        else b2.pb(-x);
    }
    reverse(b2.begin(), b2.end());
    int res = f(a1,b1) + f(a2,b2);
    cout << res << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}