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

// https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/

int getLIS(vector<int> a) {
    vector<int> tail;
    for (int i: a) {
        auto pos = lower_bound(tail.begin(), tail.end(), i);
        if (pos == tail.end()) tail.pb(i);
        else *pos = i;  
    }
    return tail.size();
}

void solve () {
    int n, m; cin >> n >> m;
    int A[n], B[m];
    for (int &i: A) cin >> i;
    for (int &i: B) cin >> i;
    
    map<int, int> mp;
    for (int i = 0; i < m; i++) mp[B[i]] = i;
    
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (mp.find(A[i]) != mp.end()) a.pb(mp[A[i]]);
    } 
    int x = getLIS(a);
    int ans = n+m-2*x;
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