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

// https://codeforces.com/contest/1101/problem/D

vi g[N+5];
int a[N+5], ans;
bool visit[N+5], isPrime[N+5];

int dfs(int u, int p, int gc) {
    visit[u] = true;
    int len = 1;
    for (int v: g[u]) {
        if (v != p && __gcd(gc, a[v]) > 1) {
            int c = dfs(v, u, __gcd(gc, a[v]));
            ans = max(ans, c+len);
            len = max(c+1, len);
        }
    }
    
    return len;
}

void solve() {  
    int n; cin >> n;
    bool isOne = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        isOne = isOne && (a[i] == 1);
    }
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    if (isOne) {
        cout << 0 << endl;
        return;
    }
    ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) dfs(i, -1, a[i]);
    }
    cout << ans << endl;
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