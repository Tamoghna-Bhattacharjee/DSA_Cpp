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
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1/#

vector<lli> getSubset(vector<lli> v, int k) {
    int n = v.size();
    vector<lli> res;
    for (int i = 0; i < (1<<n); i++) {
        lli val = 1;
        for (int j = 0; j < n; j++) {
            int F = 1 << j;
            if ((i&F)) val = val * v[j];
        }
        if (val <= k) res.pb(val); 
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int &i: a) cin >> i;
    vector<lli> v1, v2;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            if (i < n/2) v1.pb(a[i]);
            else v2.pb(a[i]);
        }
    }
    vector<lli> s1 = getSubset(v1, k);
    vector<lli> s2 = getSubset(v2, k);
    sort(s2.begin(), s2.end());
    int cnt = 0;
    for (int i: s1) cnt += upper_bound(s2.begin(), s2.end(), k/i) - s2.begin();
    cout << cnt-1 << endl;
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