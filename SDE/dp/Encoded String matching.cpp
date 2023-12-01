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

// https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/

// dp[i][j][diff] = ans for s1[i...n] s2[j...m] with len difference = diff
// diff = len(s1 after decodeing) - len(s2 after decodeing)

int dp[41][41][2000];

bool isNum(char ch) {
    return ch >= '0' && ch <= '9';
}

bool f(int i, int j, int diff, string &s1, string &s2) {
    if (i >= s1.size() && j >= s2.size()) return diff == 0;

    if (dp[i][j][diff+1000] != -1) return dp[i][j][diff+1000];

    bool ans = false;

    if (i < s1.size() && j < s2.size() 
        && s1[i]==s2[j] && !isNum(s1[i]) && diff == 0 && f(i+1,j+1,0,s1,s2)) {
        return dp[i][j][diff+1000] = true;
    }

    if (i < s1.size() && !isNum(s1[i]) && diff < 0 && f(i+1,j,diff+1, s1, s2)) 
        return dp[i][j][diff+1000] = true;
    
    if (j < s2.size() && !isNum(s2[j]) && diff > 0 && f(i,j+1,diff-1, s1, s2)) 
        return dp[i][j][diff+1000] = true;
    
    int k = i, val = 0;
    while (k < s1.size() && isNum(s1[k])) {
        val = val * 10 + s1[k] - '0';
        ans = ans | f(k+1, j, diff+val, s1, s2);
        k++;
    }

    k = j, val = 0;
    while (k < s2.size() && isNum(s2[k])) {
        val = val * 10 + s2[k] - '0';
        ans = ans | f(i, k+1, diff-val, s1, s2);
        k++;
    }
    
    return dp[i][j][diff+1000] = ans;
}

void solve() {
    string s1, s2; cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    return f(0,0,0,s1,s2);
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