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

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1581/problem/C

int dp[401][401], g[401][401];

int getVal(int i1, int j1, int i2, int j2) {
    return dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1];
}

int f(int I1, int I2, int L, int R) {
    int l = L+1, r = R-1;
    int i1 = I1+1, i2 = I2-1;
    int h = r-l+1, v = i2-i1+1;
    int tp = getVal(I1, l, I1, r), btm = getVal(I2, l, I2, r);
    int lft = getVal(i1, L, i2, L), rgt = getVal(i1, R, i2, R);
    int mid = getVal(i1, l, i2, r);
    return mid + 2*h - tp - btm + 2*v - lft - rgt;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s; s = "#" + s;
        for (int j = 1; j <= m; j++) {
            g[i][j] = s[j] - '0';
            dp[i][j] = s[j] - '0' + dp[i-1][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) dp[i][j] += dp[i][j-1];
    }
    int ans = INT_MAX;
    
    for (int L = 1; L <= m; L++) {
        for (int R = L+3; R <= m; R++) {
            vi dp(n+1, INT_MAX);
            // dp[i] -> min cost with subrect ending at ith row
            // dp[i] -> min(subrect with height=5 and ending at ith row, 
            //            min cost subrect height > 5 and ending at ith row)
            dp[5] = f(1, 5, L, R);
            for (int i = 6; i <= n; i++) {
                dp[i] = f(i-4,i,L,R);
                int pbtm = getVal(i-1, L+1, i-1, R-1);
                int btm = getVal(i, L+1, i, R-1);
                int h = (R-1) - (L + 1) + 1;
                int x = dp[i-1] - (h-pbtm) + pbtm + (h-btm) + (g[i-1][L]==0) + (g[i-1][R]==0);
                dp[i] = min(dp[i], x);
            }
            ans = min(ans, *min_element(dp.begin(), dp.end()));
        }
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
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}