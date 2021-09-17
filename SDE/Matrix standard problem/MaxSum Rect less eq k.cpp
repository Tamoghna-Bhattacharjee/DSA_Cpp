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

// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

int f(vi v, int k) {
    int ans = INT_MIN, sum = 0;
    set<int> s = {0};
    for (int i: v) {
        sum += i;
        auto lft = s.lower_bound(sum-k);
        if (lft != s.end()) ans = max(ans, sum - *lft);
        s.insert(sum);
    }
    return ans;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vi> a(n+1, vi(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j], a[i][j] += a[i][j-1];
    }  
    int ans = INT_MIN;
    for (int R = 1; R <= m; R++) {
        for (int L = 1; L <= R; L++) {
            vi v;
            for (int i = 1; i <= n; i++) v.pb(a[i][R]-a[i][L-1]);
            ans = max(ans, f(v,k));
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
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}