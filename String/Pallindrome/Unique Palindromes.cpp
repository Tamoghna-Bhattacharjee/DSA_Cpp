#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 

template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://codeforces.com/contest/1823/problem/D

void solve() {
    int n, k; cin >> n >> k;
    vi x(k+1), c(k+1);
    for (int i = 1; i <= k; i++) cin >> x[i];
    for (int i = 1; i <= k; i++) cin >> c[i];
    // if P(s) = total no of unique pallindrome in s
    // then always P(s) <= s.size();

    char cur = 'a';
    bool ok = true;
    string s;
    for (int i = 1; i <= k; i++) {
        int dx = x[i]-x[i-1];
        int dc = c[i] - c[i-1];
        if (dc > dx) {
            ok = false;
            break;
        }
        if (i == 1) dc -= 3; 
        // so that 1st block gets "abc" and thus we can use "abc" after without 
        // increasing the count
        for (int j = 0; j < dc; j++) s.pb('c' + i);
        for (int j = dc; j < dx; j++) {
            s.pb(cur);
            cur++;
            if (cur == 'd') cur = 'a';
        }
    }
    cout << YN[ok] << endl;
    if (ok) cout << s << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}