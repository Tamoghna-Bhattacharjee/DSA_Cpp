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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

void solve() {
    int n, k; cin >> n >> k;
    int p[n]; for (int &i: p) cin >> i;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    if (k >= n/2) {
        int prof = 0;
        for (int i = 1; i < n; i++) {
            if (p[i] > p[i-1]) prof += p[i] - p[i-1];
        }
        cout << prof << endl;
        return;
    }
    
    vector<int> cp(k+1, INT_MAX), prof(k+1);
    for (int i: p) {
        for (int j = 1; j <= k; j++) {
            cp[j] = min(cp[j], i - prof[j-1]);
            prof[j] = max(prof[j], i-cp[j]);
        }
    }
    cout << prof[k] << endl;
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