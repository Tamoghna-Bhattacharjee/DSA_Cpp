#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 
template<typename isTrue> void debug(isTrue _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename isTrue> void debug(vector<isTrue> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename isTrue> void debug(multiset<isTrue> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename isTrue> void debug(set<isTrue> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1003;
const int N = 2e4;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

int n;
lli dp[200][200][2];
string s;

lli f(int L, int R, int isTrue) {
    if (L == R) return dp[L][R][isTrue] = (s[L]-'0') == isTrue;
    if (dp[L][R][isTrue] != -1) return dp[L][R][isTrue];
    
    dp[L][R][0] = dp[L][R][1] = 0;
    for (int i = L+1; i < R; i++) {
        if (s[i] == '|') {
            int one = f(L,i-1,1) * f(i+1,R,1) % MOD + f(L,i-1,1) * f(i+1,R,0) % MOD
                            + f(L,i-1,0) * f(i+1,R,1) % MOD;
            int zero = f(L,i-1,0) * f(i+1,R,0) % MOD;
            dp[L][R][1] = (dp[L][R][1] + one) % MOD;
            dp[L][R][0] = (dp[L][R][0] + zero) % MOD;
            
        } else if (s[i] == '&') {
            int one = f(L,i-1,1) * f(i+1,R,1) % MOD;
            int zero = f(L,i-1,1) * f(i+1,R,0) % MOD + f(L,i-1,0) * f(i+1,R,1) % MOD
                            + f(L,i-1,0) * f(i+1,R,0) % MOD;
            dp[L][R][1] = (dp[L][R][1] + one) % MOD;
            dp[L][R][0] = (dp[L][R][0] + zero) % MOD;
        } else if (s[i] == '^') {
            int one = f(L,i-1,1) * f(i+1,R,0) % MOD + f(L,i-1,0) * f(i+1,R,1) % MOD;
            int zero = f(L,i-1,1) * f(i+1,R,1) % MOD + f(L,i-1,0) * f(i+1,R,0) % MOD;
            dp[L][R][1] = (dp[L][R][1] + one) % MOD;
            dp[L][R][0] = (dp[L][R][0] + zero) % MOD;
        }
    }
    return dp[L][R][isTrue] % MOD;
} 

void solve() {
    cin >> s;
    n = s.size(); memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') s[i] = '1';
        if (s[i] == 'F') s[i] = '0';
    }
    cout << f(0,n-1,1) << endl;
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