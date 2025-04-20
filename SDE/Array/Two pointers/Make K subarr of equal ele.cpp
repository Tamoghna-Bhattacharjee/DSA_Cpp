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

// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/

// This problem is the extention of the classic problem to find median in a stream


vlli getCnt(vi &a, int x) {
    int n = a.size();
    multiset<int> sm, gt;
    lli ss = 0, gg = 0;
    vlli res(n, INF);

    for (int i = 0; i < n; i++) {
        if (i-x >= 0) {
            if (sm.find(a[i-x]) != sm.end()) {
                sm.erase(sm.find(a[i-x]));
                ss -= a[i-x];
            } else {
                gt.erase(gt.find(a[i-x]));
                gg -= a[i-x];
            }
        }
        if (sm.size() <= gt.size()) sm.insert(a[i]), ss += a[i];
        else gt.insert(a[i]), gg += a[i];

        while (!sm.empty() && !gt.empty() && 
                *sm.rbegin() > *gt.begin()) {
            int ff = *gt.begin();
            int ll = *sm.rbegin();
            sm.erase(sm.find(ll)); ss -= ll;
            gt.erase(gt.find(ff)); gg -= ff;
            sm.insert(ff); ss += ff;
            gt.insert(ll); gg += ll; 
        }
        if (i >= x-1) {
            lli med = *sm.rbegin();
            res[i-x+1] = sm.size() * med - ss + gg - gt.size() * med;
        }
    }
    return res;
}

lli f(int i, int x, int k, vector<vlli> &dp, vi &a, vlli &op) {
    if (i+x-1 >= a.size()) return k == 0? 0: INF;
    if (k == 0) return 0;
    if (dp[i][k] != -1) return dp[i][k];
    lli ans = f(i+1,x,k,dp,a,op);
    ans = min(ans, f(i+x, x, k-1, dp, a, op) + op[i]);
    return dp[i][k] = ans;
}


void solve() {
    int n, x, k; cin >> n >> x >> k;
    vi a(n); for (auto &i: a) cin >> i;
    vlli op = getCnt(a, x);
    vector<vlli> dp(n, vlli(k+1, -1));
    cout << f(0, x, k, dp, a, op) << endl;
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