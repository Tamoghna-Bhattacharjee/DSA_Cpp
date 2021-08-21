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

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

vector<vi> j;
vi dp;

int getInd(int L, int R, int x) {
    while (L <= R) {
        int mid = (L + R) / 2;
        if (j[mid][0] >= x) R = mid - 1;
        else L = mid + 1;
    }
    return R+1;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e, p; cin >> s >> e >> p;
        j.pb({s,e,p});
    }
    dp = vi(n);
    sort(j.begin(), j.end()); 
      
    dp[n-1] = j[n-1][2];
    for (int i = n-2; i >= 0; i--) {
        dp[i] = j[i][2];
        int ind = getInd(i+1, n-1, j[i][1]);
        if (ind < n) {
            dp[i] += dp[ind];
        }
        dp[i] = max(dp[i], dp[i+1]);
    }
    cout << dp[0] << endl;
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