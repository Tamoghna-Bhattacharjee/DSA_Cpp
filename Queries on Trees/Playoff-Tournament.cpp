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
const int N = 6e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1535/problem/D

int k, n, arr[N+5], par[N+1];
string s;

void dfs(int u, int p) {
    par[u] = p;
    if (u > n) arr[u] = 1;
    else {
        dfs(2*u, u); dfs(2*u+1, u);
        if (s[u] == '0') arr[u] = arr[2*u+1];
        else if (s[u] == '1') arr[u] = arr[2*u];
        else arr[u] = arr[2*u] + arr[2*u+1];
    }
}

void upd(int u) {
    if (u == -1) return;
    if (s[u] == '0') arr[u] = arr[2*u+1];
    else if (s[u] == '1') arr[u] = arr[2*u];
    else arr[u] = arr[2*u] + arr[2*u+1];
    upd(par[u]);
}

void solve() {
    cin >> k; n = (1<<k) - 1;
    cin >> s; s.pb('#');
    reverse(s.begin(), s.end());
    dfs(1,-1);
    
    int q; cin >> q;
    while (q--) {
        int p; char c; cin >> p >> c; 
        s[n+1-p] = c;
        upd(n+1-p);
        cout << arr[1] << endl;
    }
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