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

// https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s; s = "#" + s;

    vlli left(n+1), pref(n+1);
    int L = 1, R = 1;
    int cnt[2] = {0,0};

    while (R <= n) {
        cnt[s[R]-'0']++;
        while (L <= R && cnt[0] > k && cnt[1] > k) cnt[s[L]-'0']--, L++;
        left[R] = L;
        pref[R] = R-L+1;
        R++;
    }

    for (int i = 1; i <= n; i++) pref[i] += pref[i-1];

    vlli ans;
    while (q--) {
        int l, r; cin >> l >> r;
        l++; r++;
        L = l, R = r;
        int idx = -1;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (left[mid] >= l) idx = mid, R = mid - 1;
            else L = mid + 1;
        }
        lli dist = 0, sum = 0;
        if (idx != -1) {
            dist = idx-l;
            sum = dist * (dist + 1) / 2;
            sum += pref[r] - pref[idx-1];
        } else {
            dist = r-l+1;
            sum = dist * (dist + 1) / 2;
        }
        ans.pb(sum);
    }
    debug(ans);
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