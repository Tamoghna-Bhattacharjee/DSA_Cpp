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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1/?track=amazon-dynamic-programming&batchId=192#

vector<vi> buySellstockWithExactDate(vi p, int n) {
    vector<vector<int>> res;
    if (n == 1) return res;
    for (int i = 0; i < n; i++) {
        int lft = i-1 >= 0? p[i-1]: INT_MAX;
        int rgt = i+1 < n? p[i+1]: INT_MAX;
        if (lft >= p[i] && p[i] <= rgt) res.push_back({i,i});
        lft = i-1 >= 0? p[i-1]: INT_MIN;
        rgt = i+1 < n? p[i+1]: INT_MIN;
        if (lft <= p[i] && p[i] >= rgt) {
            if (res.empty()) continue;
            else if (res.back()[0] == res.back()[1]) res.back()[1] = i;
        }
    }
    if (res.back()[0] == res.back()[1]) res.pop_back();
    return res;
} 

void solve() {
    int n; cin >> n;
    vi p(n); for (int &i: p) cin >> i;
    int cp = INT_MAX, prof = 0;
    for (int i: p) {
        cp = min(cp, i-prof);
        prof = max(prof, i-cp);
    }
    cout << prof << endl;
    debug(buySellstockWithExactDate(p,n));
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