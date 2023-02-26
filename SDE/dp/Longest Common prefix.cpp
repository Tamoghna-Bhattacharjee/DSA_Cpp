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

// lcp[i][j] is equal to the length of the longest common prefix 
// between the substrings s[i,n-1] and s[j,n-1].
// find the maximum lcp for a given s over all its substrings such that i != j

// related qs: https://leetcode.com/problems/find-the-string-with-lcp/description/

int f(int i, int j, int n, vector<vector<int>>& lcp, string &s) {
    if (i >= n || j >= n) return 0;
    if (lcp[i][j] != -1) return lcp[i][j];
    if (s[i] == s[j]) lcp[i][j] = 1 + f(i+1, j+1, n, lcp, s);
    else lcp[i][j] = 0;
    return lcp[i][j];
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    int mx = 0;
    vector<vi> lcp(n, vi(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f(i, j, n, lcp, s);
            if (i != j) mx = max(mx, lcp[i][j]); 
            cout << lcp[i][j] << " ";
        }
        cout << endl;
    }
    cout << mx << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}