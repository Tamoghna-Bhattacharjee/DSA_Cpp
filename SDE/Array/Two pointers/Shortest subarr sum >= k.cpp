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

// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

// Can also be solved using segment tree (Max subarr sum) and sliding window
// Sol: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/submissions/1471224384/

void PriorityQueueSol(vi &a, int n, int k) {
    priority_queue<pair<lli, lli>> pq;
    pq.push({0,-1});

    lli sum = 0, ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        while (!pq.empty() && sum + pq.top().first >= k) {
            ans = min(ans, i-pq.top().second);
            pq.pop();
        }
        pq.push({-sum, i});
    }
    
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}

void monotonicSolution(vi &a, int n, int k) {
    vlli pref(n+1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];
    
    deque<int> dq;
    dq.push_back(0);
    
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && pref[i]-pref[dq.front()] >= k) {
            ans = min(ans, i-dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && pref[dq.back()] >= pref[i]) dq.pop_back();
        dq.push_back(i);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    monotonicSolution(a, n, k);
    PriorityQueueSol(a, n, k);
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