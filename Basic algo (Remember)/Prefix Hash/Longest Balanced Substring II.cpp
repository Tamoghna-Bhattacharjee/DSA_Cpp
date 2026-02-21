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

// https://leetcode.com/problems/longest-balanced-substring-ii/description/

// You are given a string s consisting only of the characters 'a', 'b', and 'c'.
// A substring of s is called balanced if all distinct characters in the
// substring appear the same number of times.
// Return the length of the longest balanced substring of s.

// Considering one distince char
int f1(string &s) {
    int ans = 0, cnt = 0;
    char ch = ' ';
    for (char i: s) {
        if (i != ch) ans = max(ans, cnt), cnt = 1, ch = i;
        else cnt++;
    }
    ans = max(ans, cnt);
    return ans;
}

// Considering 2 distinct char
int f2(string &s, char a, char b) {
    int ans = 0, sum = 0, n = s.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == a) sum++;
        else if (s[i] == b) sum--;
        else {
            sum = 0;
            mp.clear();
            mp[0] = i;
            continue;
        }
        if (mp.find(sum) == mp.end()) mp[sum] = i;
        else ans = max(ans, i-mp[sum]);
    }
    return ans;
}

// Considering 3 distinct char
int f3(string &s) {
    int n = s.size();
    int cnt[3] = {0, 0, 0}, ans = 0;
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = -1;
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
        pair<int, int> p = {cnt[1]-cnt[0], cnt[2]-cnt[0]};
        if (mp.find(p) == mp.end()) mp[p] = i;
        else ans = max(ans, i-mp[p]);
    }
    return ans;
}

void solve() {
    string s; cin >> s;
    int ans = f1(s);
    for (int i = 0; i < 3; i++) {
        ans = max(ans, f2(s, 'a' + (i+1)%3, 'a' + (i+2)%3));
    }
    ans = max(ans, f3(s));
    cout << ans << endl;;
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