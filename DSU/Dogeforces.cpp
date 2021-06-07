#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 500;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1494/problem/D

int n, k;
int a[N+5][N+5], dsu[N*N + 5], s[N*N + 5]; // s -> salary
vector<pair<int, int>> ans;

int findNode(int a) {
    if (dsu[a] < 0) return a;
    return dsu[a] = findNode(dsu[a]);
}

void solve() {
    memset(dsu, -1, sizeof dsu);
    cin >> n;
    vector<pair<int, pair<int, int>>> l;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i == j) s[i] = a[i][j];
            else if (j > i) l.pb({a[i][j], {i, j}});
        }
    }
    sort(l.begin(), l.end());
    int k = n;
    for (auto i: l) {
        int sal = i.first, u = i.second.first, v = i.second.second;
        u = findNode(u); v = findNode(v);
        if (u == v) continue;
        else if (max(s[u], s[v]) == sal) {
            if (s[u] > s[v]) {
                dsu[v] = u;
                ans.pb({v,u});
            } else dsu[u] = v, ans.pb({u,v});
        } else{
            ++k;
            dsu[u] = dsu[v] = k;
            dsu[k] = -3;
            ans.pb({u,k});
            ans.pb({v,k});
            s[k] = sal;
        }
    }
    cout << k << endl;
    for (int i = 1; i <= k; i++) cout << s[i] << " "; cout << endl;
    cout << k << endl;
    for (auto i: ans) cout << i.first << " " << i.second << endl;

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
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}