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

// https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/

// We need the min time to revert back
// We take the longest prefix which is also a sufix for string s[0 ... n-1] i.e LPS[n-1]
// let len = LPS[n-1];
// remaining elements => rem = (n-len), if (n-len) % k == 0 ===> We can have (n-len)/k divisions
// otherwise since we have to find the longest pref which is also sufix
//      in s[(n-1) - len + 1 ... n] ==> s[0 ... LPS[len-1]]

vi getLPS(string &s) {
    int n = s.size();
    vi LPS(n);
    int j = 0, i = 1;
    while (i < n) {
        if (s[i] == s[j] || s[i] == '*') LPS[i++] = ++j;
        else {
            if (j == 0) i++;
            else j = LPS[j-1];
        }
    }
    return LPS;
}

void solve() {
    string s;
    int k;
    cin >> s >> k;
    vi LPS = getLPS(s);
    int len = LPS[n-1];
    while (len > 0 && (n-len) % k) len = LPS[len-1];
    cout << (n-len+k-1)/k << endl;
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