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

// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

// Intuition: #start <= pi - #end < pi

int getCnt(vector<int> &a, int x, string s) {
    int L = 0, R = a.size()-1, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (s == "<=") {
            if (a[mid] <= x) ans = mid + 1, L = mid + 1;
            else R = mid - 1;
        } else {
            if (a[mid] < x) ans = mid + 1, L = mid + 1;
            else R = mid - 1;
        }
    }
    return ans;
} 

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& p) {
    int n = flowers.size();
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        L[i] = flowers[i][0];
        R[i] = flowers[i][1];
    }
    sort(L.begin(), L.end()); sort(R.begin(), R.end());
    vector<int> res;
    for (int i: p) {
        res.push_back(getCnt(L, i, "<=") - getCnt(R, i, "<"));
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> flowers(n, vector<int>(2));
    for (auto &i: flowers) cin >> i[0] >> i[1];
    vector<int> people(m); 
    for (auto &i: people) cin >> i;
    debug(fullBloomFlowers(flowers, people));
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