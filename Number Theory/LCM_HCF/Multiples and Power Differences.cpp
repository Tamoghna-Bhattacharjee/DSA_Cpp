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
const int N = 1e3;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1485/problem/D

int getLCM(int L, int R) {
    int lcm = L;
    for (int i = L+1; i <= R; i++) {
        lcm = (lcm * i) / __gcd(lcm, i);
    }
    return lcm;
}

void solve() {  
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) cin >> a[i][j];
    int lcm = getLCM(1,16);
    int b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i+j)%2 == 0) b[i][j] = lcm;
            else b[i][j] = lcm + pow(a[i][j], 4);
            cout << b[i][j] << " ";
        }
        cout << endl;
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