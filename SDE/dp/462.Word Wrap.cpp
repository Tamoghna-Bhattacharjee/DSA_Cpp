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
const int N = 2e4;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://practice.geeksforgeeks.org/problems/word-wrap1646/1#

void solve() {
    int n, k; cin >> n >> k;
    int a[n]; for (int &i: a) cin >> i;
    int dp[n], end[n]; 
    // dp[i] -> total cost for a[i..n-1] with the line beginning with a[i]
    // end[i] -> index with which the line started with a[i] ends.
    dp[n-1] = 0; // when last word is used the extra rem space in the line is not considered
    end[n-1] = n-1; // if line start with n-1 it would also end with n-1;

    for (int i = n-2; i >= 0; i--) {
        int len = -1;
        dp[i] = INT_MAX;
        for (int j = i; j < n; j++) {
            len += a[j] + 1;
            if (len > k) break;
            if (j == n-1) dp[i] = 0, end[i] = j;
            else {
                int cost = (k-len) * (k-len) + dp[j+1];
                if (cost < dp[i]) dp[i] = cost, end[i] = j;
            } 
        }
    }
    cout << "Total cost = " << dp[0] << endl;
    cout << "Word wrapping" << endl;
    int i = 0;
    while (i < n) cout << i << " " << end[i] << endl, i = end[i] + 1;

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