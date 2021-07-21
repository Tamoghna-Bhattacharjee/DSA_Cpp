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

// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

vi a;
int n, m;

bool check(int sum) {
    vi v;
    for (int i: a) {
        if (!v.empty() && v.back() + i <= sum) v.back() += i;
        else v.pb(i);
    }
    return v.size() <= m;
}

void solve () {
    cin >> n; a = vi(n);
    int sum = 0;
    for (int &i: a) cin >> i, sum += i;
    cin >> m;

    if (m > n) {
        cout << -1 << endl; return;
    }
    int L = *max_element(a.begin(), a.end()), R = sum, ans = sum;
    while (L <= R) {
        int mid = (L + R) /2;
        if (check(mid)) ans = min(ans, mid), R = mid - 1;
        else L = mid + 1;
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