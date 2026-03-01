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

// https://leetcode.com/problems/minimum-operations-to-equalize-binary-string

/*
You are given a binary string s, and an integer k.

In one operation, you must choose exactly k different indices and flip
each '0' to '1' and each '1' to '0'.

Return the minimum number of operations required to make all characters in the 
string equal to '1'. If it is not possible, return -1.
*/

void solve() {
    string s; cin >> s;
    int k; cin >> k;

    int n = s.size(), cnt0 = 0;
    for (char i: s) cnt0 += i == '0';
    vlli dist(n+1, INT_MAX);
    set<int> unvisit[2];
    for (int i = 0; i <= n; i++) unvisit[i%2].insert(i);
    queue<int> q;

    dist[cnt0] = 0;
    q.push(cnt0);
    unvisit[cnt0%2].erase(cnt0);

    while (!q.empty()) {
        int cnt = q.front(); q.pop();
        int max_i = min(cnt, k);
        int min_i = max(0, k - (n - cnt));

        int L = cnt + k - 2 * max_i;
        int R = cnt + k - 2 * min_i;
        auto it = unvisit[L%2].lower_bound(L);
        while (it != unvisit[L%2].end() && *it <= R) {
            int ncnt = *it;
            q.push(ncnt);
            dist[ncnt] = dist[cnt] + 1;
            it = unvisit[L%2].erase(it);
        }
    }
    int ans = dist[0] == INT_MAX? -1: dist[0];
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
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}