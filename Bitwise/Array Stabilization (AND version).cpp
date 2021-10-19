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

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const lli INF = 1e18, MOD = 998244353;
const int N = 2e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1579/problem/F

void solve() {
    int n, d; cin >> n >> d;
    vi a(n);
    for (int &i: a) cin >> i;
    vector<vi> g;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(i) != s.end()) continue;
        int x = i;
        vi temp;
        while (s.find(x) == s.end()) {
            s.insert(x);
            temp.pb(a[x]);
            x = (x+d)%n;
        }
        int sz = temp.size();
        for (int i = 0; i < sz; i++) temp.pb(temp[i]);
        g.pb(temp);
    }
    int ans = 0;
    for (vi i: g) {
        int mx = 0, sum = 0;
        for (int j: i) {
            if (j == 0) sum = 0;
            else {
                sum++;
                mx = max(mx, sum);
            }
        }
        if (mx == i.size()) {
            cout << -1 << endl;
            return;
        }
        ans = max(mx, ans);
    }
    cout << ans << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}