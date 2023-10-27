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

// https://leetcode.com/problems/the-skyline-problem/
// idea is to add height first and remove when the right end of a particular height is reached
// if any change happens b/w current height and ongoing height add the required point to ans

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(3));
    for (auto &i: a) {
        for (auto &j: i) cin >> j;
    }
    vector<pair<int, int>> v;
    for (auto &i: a) {
        v.push_back({i[0], -i[2]}); // adding height should be first
        v.push_back({i[1], i[2]});
    }
    sort(v.begin(), v.end());
    int curH = 0;
    multiset<int> s; s.insert(0);
    vector<vector<int>> ans;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second < 0) {
            s.insert(-v[i].second);
        } else s.erase(s.find(v[i].second));
        int mx = *s.rbegin();
        if (mx != curH) {
            curH = mx;
            ans.pb({v[i].first, curH});
        }
    }

    for (auto &i: ans) debug(i);
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