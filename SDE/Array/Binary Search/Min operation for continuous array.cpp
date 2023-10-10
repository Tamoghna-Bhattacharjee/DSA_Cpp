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

// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
// Intuition: For each element fix the left as a[i] and check how many element are there
// within a[i]+n-1 from ith loc.

void usingSlidingWindow(vector<int>& a) {
    int n = a.size();
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    int ans = n;
    for (int i = 0, j = 0; i < b.size(); i++) {
        int start = b[i], end = b[i]+n-1;
        while (j < b.size() && b[j] <= end) {
            ans = min(ans, n-(j-i+1));
            j++;
        }
    }
    cout << ans << endl;
}

void solveWithBinarySearch(vector<int> &a) {
    int n = a.size();
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    int ans = n;
    for (int i = 0; i < b.size(); i++) {
        int start = b[i], end = b[i]+n-1;
        int L = i, R = b.size()-1, idx = i;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (b[mid] <= end) idx = mid, L = mid + 1;
            else R = mid - 1;
        }
        int sz = idx-i+1;
        ans = min(ans, n-sz);
    }
    cout << ans << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;
    solveWithBinarySearch(a);
    usingSlidingWindow(a);
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