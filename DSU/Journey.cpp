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
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1476/problem/D

vi dsu;

int findNode(int a) {
    if (dsu[a] < 0) return a;
    return dsu[a] = findNode(dsu[a]);
}

void unionNode(int a, int b) {
    a = findNode(a); b = findNode(b);
    if (a == b) return;
    if (dsu[a] <= dsu[b]) swap(a, b);
    dsu[b] += dsu[a];
    dsu[a] = b;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    dsu = vi(3*n + 5, -1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') unionNode(i, 2*n + i - 1); // (i,0) -> (i-1, 1)
        else unionNode(i-1, 2*n + i);   // (i-1, 0) -> (i, 1)
    }

    for (int i = 0; i <= n; i++) cout << -dsu[findNode(i)] << " "; cout << endl;
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) solve();
}