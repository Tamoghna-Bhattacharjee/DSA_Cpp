#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 998244353;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

vector<vi> j;

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
    vi start(n), end(n), prof(n);
    for (int &i: start) cin >> i;
    for (int &i: end) cin >> i;
    for (int &i: prof) cin >> i;
    
    j = vector<vi>(n);
    for (int i = 0; i < n; i++) j[i] = {start[i], end[i], prof[i]};
    sort(j.begin(), j.end());
    
    vi dp(n); // dp[i] = max prof in the range jobs[i..n-1]
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