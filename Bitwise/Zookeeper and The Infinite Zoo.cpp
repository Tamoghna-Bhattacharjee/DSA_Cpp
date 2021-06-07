#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1491/problem/D

bool isConnected(int a, int b) {
    if (a > b) return false;
    if (a == b) return true;
    int cnt[] = {0, 0}; // 0th index - a, 1 index for b
    for (int i = 0; i <= 30; i++) {
        int F = 1 << i;
        if ((a & F) != 0) cnt[0]++;
        if ((b & F) != 0) cnt[1]++;
        if (cnt[1] > cnt[0]) return false; 
    }
    return true;
}
void solve() {  
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << YN[isConnected(a, b)] << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) solve();
}