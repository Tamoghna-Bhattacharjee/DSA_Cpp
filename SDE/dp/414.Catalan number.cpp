#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e8;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://leetcode.com/problems/unique-binary-search-trees/submissions/
// https://www.geeksforgeeks.org/program-nth-catalan-number/
// Catalan numbers are a sequence of natural numbers that occurs in many interesting counting 
// problems like following.
// Count the number of expressions containing n pairs of parentheses which are correctly matched. 
// Count the number of possible Binary Search Trees with n keys.(Same code)
// Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points 
// such that no 2 chords intersect.

// let f(n) = catalan number at index n
// f(0) = 1 and f(n) = ∑ f(i-1) * f(n-i) for i in range[1, n]
// or f(n) = ∑ f(i)*f(n-i-1) for i in range[0, n-1]
// in short f(n) = (2nCn)/(n+1) = (2n!)/((n+1)*n!*n!)

void solve() {
    int n; cin >> n;
    vector<lli> dp(n+1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        lli sum = 0;
        for (int j = 1; j <= i; j++) {
            sum += dp[j-1] * dp[i-j];
        }
        dp[i] = sum;
    }
    cout << dp[n] << endl;
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