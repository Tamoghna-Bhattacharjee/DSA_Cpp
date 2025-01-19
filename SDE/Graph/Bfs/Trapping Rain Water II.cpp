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
#define all(__x) __x.begin(),__x.end()

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

// https://leetcode.com/problems/trapping-rain-water-ii/description/

int n, m;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve() {
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (auto &i: a) {
        for (auto &j: i) cin >> j;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n-1 || j == m-1)
                pq.push({-a[i][j], {i, j}}), a[i][j] = -1;
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        auto [H, coor] = pq.top(); pq.pop();
        auto &[i, j] = coor;
        H *= -1;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (isValid(ni, nj) && a[ni][nj] != -1) {
                if (a[ni][nj] < H) {
                    ans += H-a[ni][nj];
                }
                pq.push({-max(a[ni][nj], H), {ni, nj}});
                a[ni][nj] = -1;
            }
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
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}