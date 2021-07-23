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

const lli INF = 1e18, MOD = 1e6+3;
const int N = 2000;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/problemset/problem/231/C

vlli a, pref;
lli n, k;

lli check(lli len) {
    for (int i = len; i <= n; i++) {
        lli reqAdd = len * a[i] - (pref[i] - pref[i-len]);
        if (reqAdd <= k) return a[i];
    }
    return INF;
}

void solve() {
    cin >> n >> k;
    a = vlli(n+1);
    pref = vlli(n+5, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    for (int i = 1; i <= n; i++) pref[i] += pref[i-1] + a[i];
    
    lli L = 1, R = n;
    pair<lli, lli> ans = {1, a[1]};
    while (L <= R) {
        lli mid = (L + R) / 2;
        lli x = check(mid);
        
        if (x == INF) R = mid - 1;
        else {
            if (mid > ans.first) ans = {mid, x};
            else ans.second = min(ans.second, x);
            L = mid + 1;
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}