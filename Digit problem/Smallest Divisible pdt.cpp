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

// https://leetcode.com/problems/smallest-divisible-digit-product-ii

string smallestNumber(string num, long long t) {
    lli tt = t;
    for (int i = 2; i <= 9 && tt > 1; i++) {
        while (tt % i == 0) tt /= i; 
    }
    
    if (tt > 1) return "-1";
    
    int n = num.size();
    int pos = n-1;
    vlli rem(n);
    rem[0] = t / gcd(t, (lli) (num[0]-'0'));

    for (int i = 1; i < n; i++) {
        if (num[i] == '0') {
            pos = i;
            break;
        }
        rem[i] = rem[i-1] / gcd(rem[i-1], (lli) (num[i]-'0'));
    }

    if (rem.back() == 1) return num;

    for (int i = pos; i >= 0; i--) {
        while (++num[i] <= '9') {
            tt = i > 0? rem[i-1]: t;
            tt = tt / gcd(tt, (lli) (num[i]-'0'));
            for (int j = n-1; j > i; j--) {
                lli k = 9;
                while (tt % k) k--;
                num[j] = '0' + k;
                tt /= k;
            }
            if (tt == 1) return num;
        }
    }

    string ans = "";
    while (t > 1) {
        lli k = 9;
        while (t % k) k--;
        t /= k;
        ans.pb(k+'0');
    }
    while (ans.size() < n+1) ans.pb('1');
    reverse(all(ans));
    return ans;
}

void solve() {
    string num; cin >> num;
    lli t; cin >> t;
    cout << smallestNumber(num, t) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; // cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}