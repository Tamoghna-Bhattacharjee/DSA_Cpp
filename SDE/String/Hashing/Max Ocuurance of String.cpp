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

// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

vlli hashVal, power;
lli n, p = 31;

void mkHash(string s) {
    power[0] = 1;
    for (int i = 0; i < n; i++) {
        power[i+1] = power[i] * p % MOD;
        hashVal[i+1] = (hashVal[i] + power[i] * (s[i]-'a'+1) % MOD) % MOD; 
    }
}

lli getHash(int L, int R) {
    return (hashVal[R+1] - hashVal[L] + MOD) % MOD * power[n-L-1] % MOD;
}

int getCntUnique(vi &F) {
    int cnt = 0;
    for (auto &i: F) cnt += i > 0;
    return cnt;
}

int getCnt(string s, int x, int ltr) {
    vi F(26);
    map<lli, int> mp;
    for (int R = 0, L = 0; R < n; R++) {
        F[s[R]-'a']++;
        while (R-L+1 > x || getCntUnique(F) > ltr) F[s[L]-'a']--, L++;
        if (R-L+1 == x && getCntUnique(F) <= ltr) {
            mp[getHash(L,R)]++;
        }
    }
    int ans = 0;
    for (auto &i: mp) ans = max(ans, i.second);
    return ans;
}

int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    n = s.size();
    hashVal = vlli(n+1);
    power = vlli(n+1);
    mkHash(s);
    return getCnt(s, minSize, maxLetters);
}

void solve() {
    string s; cin >> s;
    int mxLtr, mnSz, mxSz; cin >> mxLtr >> mnSz >> mxSz;
    cout << maxFreq(s, mxLtr, mnSz, mxSz) << endl;
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