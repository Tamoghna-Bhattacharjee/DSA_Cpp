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

// https://leetcode.com/problems/beautiful-towers-ii/
// Use the idea of next-smaller from both left and right side

void solve() {
    int n; cin >> n;
    vlli a(n); for (auto &i: a) cin >> i;

    // next smaller on left
    vlli left(a.begin(), a.end());
    stack<int> s; s.push(0);
    for (lli i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) {
            left[i] += left[i-1];
            s.push(i);
        } else {
            while (!s.empty() && a[s.top()] > a[i]) s.pop();
            if (!s.empty()) left[i] = a[i] * (i-s.top())+ left[s.top()];
            else left[i] = a[i] * (i+1);
            s.push(i);
        }
    }

    // next smaller on right
    vlli right(a.begin(), a.end());
    s = stack<int>();
    s.push(n-1);
    for (lli i = n-2; i >= 0; i--) {
        if (a[i] >= a[i+1]) {
            right[i] += right[i+1];
            s.push(i);
        } else {
            while (!s.empty() && a[s.top()] > a[i]) s.pop();
            if (!s.empty()) right[i] = a[i] * (s.top()-i)+ right[s.top()];
            else right[i] = a[i] * (n-i);
            s.push(i);
        }
    }

    lli ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, left[i] + right[i] - a[i]);
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