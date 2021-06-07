#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
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

const lli INF = 1e18, MOD = 1e8;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

vi a;
vector<vi> dp;
int n;

int f(int i, int j) {
    if (i == j) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];
    int sum = INT_MAX;
    for (int k = i; k < j; k++) 
        sum = min(sum, f(i, k) + f(k+1, j) + a[i-1] * a[k] * a[j]);
    return dp[i][j] = sum;
}

void solve() {
    cin >> n; 
    a = vi(n+1);
    dp = vector<vi>(n+1, vi(n+1, -1));
    for (int &i: a) cin >> i;
    cout << f(1, n) << endl;
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