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
const int N = 3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://leetcode.com/problems/maximal-rectangle/

int maxHist(vector<int> a) {
    int n = a.size();
    stack<int> s;
    int i = 0;
    int res = 0;
    while (i < n) {
        if (s.empty() || a[s.top()] <= a[i]) s.push(i++);
        else {
            int h = a[s.top()]; s.pop();
            int b = s.empty()? i: i-1-s.top();
            res = max(res, h*b);
        }
    }
    while (!s.empty()) {
        int h = a[s.top()]; s.pop();
        int b = s.empty()? i: i-1-s.top();
        res = max(res, h*b);
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    int M[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) cin >> M[i][j];
    vector<int> dp(m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) dp[j] = 0;
            else dp[j] += M[i][j];
        }
        ans = max(ans, maxHist(dp));
    }
    cout << ans << endl;
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