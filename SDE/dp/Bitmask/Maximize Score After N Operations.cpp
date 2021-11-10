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

const lli INF = 1e15, MOD = 1e9+7;
const int N = 4e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://leetcode.com/problems/maximize-score-after-n-operations/

vi a;
vector<vi> dp;
int n, m;

int f(int k, int mask) {
    if (k > n) return 0;
    if (dp[mask][k] != -1) return dp[mask][k];
    
    for (int i = 0; i < m-1; i++) {
        int F1 = (1 << i);
        if ((mask & F1)) continue;
        for (int j = i+1; j < m; j++) {
            int F2 = (1 << j);
            if (mask & F2) continue;
            dp[mask][k] = max(dp[mask][k], k * __gcd(a[i], a[j]) + f(k+1, mask+F1+F2));
        }
    }
    return dp[mask][k];
}

void solve() {
    cin >> n;
    m = 2*n;
    a = vi(m); for (int &i: a) cin >> i;
    dp = vector<vi> ((1<<m) + 1, vi(n+1, -1));
    cout << f(1, 0) << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}