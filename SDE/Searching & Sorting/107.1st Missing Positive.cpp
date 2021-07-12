#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 4e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};  

// https://leetcode.com/problems/first-missing-positive/

// Idea -> 1st missing +ve element of array of size n lies b/w [1...n+1]
// use array index as hash
// arrange the array such that a[i] = i+1 i.e a[0] = 1, a[1] = 2 etc.
// the 1st number where this seq break is the ans.

void solve() {
    int n; cin >> n;
    int a[n]; 
    for (int &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        while (a[i] > 0 && a[i] <= n && a[a[i] - 1] != a[i]) swap(a[i], a[a[i]-1]);
    }
    int ans = n+1;
    for (int i = 0; i < n; i++) {
        if (a[i] != i+1) {
            ans = i+1; break;
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