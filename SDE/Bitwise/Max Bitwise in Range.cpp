#include <bits/stdc++.h>
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
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 5e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// Max Xor pair
// https://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/

// Max Bitwise And in a range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

int getMaxXorPair(int L, int R) {
    int x = L ^ R;
    int ans = 0;
    for (int i = log2(x); i >= 0; i--) ans += 1 << i;
    return ans;
}

int getMaxAnd(int L, int R) {
    /*
        R > L
        Let R = 101101000
            L = 101011110
        for any set bit in R if there are setbit on smaller bits in L we can remove that
        set bit from R

        Removing set bit nearest to LSB => x & (x-1)
    */

    while (R > L) R = R & (R-1);
    return R & L;
}

void solve() {
    int L, R; cin >> L >> R;
    cout << getMaxXorPair(L, R) << endl;
    cout << getMaxAnd(L, R) << endl;
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