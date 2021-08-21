#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 5e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#

vlli a;
vector<vector<lli>> dp;

lli f(int L, int R) {
    if (L > R) return 0;
    if (L == R) return dp[L][R] = a[L];
    if (dp[L][R] != -1) return dp[L][R];
    return dp[L][R] = max(a[L] + min(f(L+2,R), f(L+1,R-1)), 
                            a[R] + min(f(L,R-2), f(L+1,R-1)));
}

void solve() {
    int n; cin >> n;
    a = vlli(n); for (lli &i: a) cin >> i;
    dp = vector<vlli>(n, vlli(n,-1));
    cout << f(0,n-1) << endl;
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
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}