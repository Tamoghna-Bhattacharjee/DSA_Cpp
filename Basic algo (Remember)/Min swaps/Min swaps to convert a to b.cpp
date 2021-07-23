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

// https://www.geeksforgeeks.org/minimum-swaps-to-make-two-array-identical/
// Note array a and b has same elements and all elements are distinct

vi visit;

void dfs(int i, vi g) {
    visit[i] = 1;
    if (visit[g[i]] == 0) dfs(g[i], g);
}

void solve () {
    int n; cin >> n;
    vi a(n), b(n);
    visit = vi(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; mp[a[i]] = i;
    }
    for (int &i: b) cin >> i;
    for (int i = 0; i < n; i++) b[i] = mp[b[i]];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visit[i] == 0) {
            dfs(i, b); cnt++;
        }
    }
    cout << n-cnt << endl;
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