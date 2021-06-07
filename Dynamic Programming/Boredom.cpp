#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i);}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e6+3;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/455/problem/A

void solve() {
    int n; cin >> n;
    map<lli, lli> mp;
    for (int i = 0; i < n; i++) {
        lli x; cin >> x; mp[x]++;
    }
    vector<pair<lli, lli>> v; v.pb({INF, 0});
    for (auto i: mp) v.pb(i);
    sort(v.begin()+1, v.end());
    n = (int) v.size()-1;
    vlli dp(n+1);
    for (int i = 1; i <= n; i++) {
        if (v[i-1].first == v[i].first - 1) 
            dp[i] = max(v[i].first * v[i].second + (i-2 >= 0? dp[i-2]: 0), dp[i-1]);
        else 
            dp[i] = v[i].first * v[i].second + dp[i-1];
    }
    cout << dp[n] << endl;
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
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}