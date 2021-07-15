#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};  

// https://codeforces.com/contest/1543/problem/D2

int knxor(int x, int y, int k) {
    int res = 0, pow = 1;
    while (x > 0 || y > 0) {
        int a = x%k, b = y % k;
        res += pow * ((k + a - b)%k);
        x /= k; y /= k;
        pow *= k; 
    }
    return res;
}

void solve () {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << i << endl;
        else if (i%2 == 1) cout << knxor(i-1, i, k) << endl;
        else cout << knxor(i,i-1,k) << endl;
        int r; cin >> r;
        if (r == 1) break;
    }
}  

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}