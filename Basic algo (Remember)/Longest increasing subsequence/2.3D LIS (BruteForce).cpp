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

// https://practice.geeksforgeeks.org/problems/box-stacking/1/

void solve() {
    int n; cin >> n;
    int h[n], w[n], l[n];
    for (auto &i: h) cin >> i;
    for (auto &i: w) cin >> i;
    for (auto &i: l) cin >> i;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        vector<int> temp = {h[i], w[i], l[i]};
        sort(temp.begin(), temp.end());
        do {
            v.push_back(temp);
        } while (next_permutation(temp.begin(), temp.end()));
    }
    int m = v.size();
    
    sort(v.begin(), v.end());
    vector<int> dp(m);
    for (int i = 0; i < m; i++) dp[i] = v[i][2];
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i][0] > v[j][0] && v[i][1] > v[j][1]) {
                dp[i] = max(dp[i], dp[j]+v[i][2]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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