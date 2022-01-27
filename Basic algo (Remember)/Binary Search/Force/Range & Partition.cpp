#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

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
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1631/problem/D

pair<int, int> check(int x, int n, int k, vi &dp) {
    int L = 1, R = x;
    int sum = dp.back();
    pair<int, int> res = {-1,-1};
    while (R <= n) {
        int inside = dp[R]-dp[L-1];
        int outside = sum-inside;
        if (inside-outside >= k) {
            res = {L,R};
            break;
        }
        L++; R++;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    vi dp(n+1);
    for (int i = 1; i <= n; i++) dp[a[i]]++;
    for (int i = 1; i <= n; i++) dp[i]+=dp[i-1];
    int L = 1, R = n;
    pair<int, int> xy;
    while (L <= R) {
        int mid = (L + R) / 2;
        pair<int, int> p = check(mid, n, k, dp);
        if (p.first != -1) R = mid - 1, xy = p;
        else L = mid + 1;
    }
    vpii res;
    L = 1, R = 1;
    int sum = 0;
    while (R <= n) {
        if (res.size() == k-1) {
            res.pb({L, n}); break;
        } else {
            sum += (a[R] >= xy.first && a[R] <= xy.second)? 1: -1;
            if (sum > 0) {
                res.pb({L,R}); R++; L = R;
                sum = 0;
            } else R++;
        }
    }
    cout << xy.first << " " << xy.second << endl;
    for (auto i: res) cout << i.first << " " << i.second << endl;
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