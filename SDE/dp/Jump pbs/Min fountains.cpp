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
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 998244353;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

// guarden -> [0,..,n] -> n+1 taps are there

int minTaps(int n, vector<int>& a) {
    vector<int> dp(n+1,-1); // dp[i] = max ind till which one can jump from i
    
    for (int i = 0; i <= n; i++) {
        dp[max(0,i-a[i])] = i+a[i];
    }
    
    int cnt = 1;
    int curReach = dp[0], mxReach = -1;
    for (int i = 0; i <= n; i++) {
        if (curReach >= n) break;
        mxReach = max(mxReach, dp[i]);
        if (i == curReach) {
            cnt++;
            curReach = mxReach;
        }
    }
    return curReach >= n? cnt: -1;
    
}

void solve() {
    int n; cin >> n;
    vi a(n+1); for (int &i: a) cin >> i;
    cout << minTaps(n,a) << endl;
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