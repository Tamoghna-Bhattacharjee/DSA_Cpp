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

const lli INF = 1e18, MOD = 1e9+7;
const int N = 3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/359/problem/D

int g[4*N+4], mi[4*N+4], a[N+1], n; // mi -> segtree of min, g - > segtree of gcd

void build(int si, int ss, int se) {
    if (ss > se) return;
    if (ss == se) {
        g[si] = a[ss];
        mi[si] = a[ss];
        return;
    }
    int mid = (ss + se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    g[si] = __gcd(g[2*si], g[2*si+1]);
    mi[si] = min(mi[2*si], mi[2*si+1]);
}

pair<int, int> qry(int si, int ss, int se, int qs, int qe) {
    if (qs > se || qe < ss || ss > se) return {0, INT_MAX};
    if (ss >= qs && se <= qe) return {g[si], mi[si]};
    int mid = (ss + se)/2;
    pair<int, int> l = qry(2*si, ss, mid, qs, qe);
    pair<int, int> r = qry(2*si+1, mid+1, se, qs, qe);
    return {__gcd(l.first, r.first), min(l.second, r.second)};
}

bool check(int x) {
    int L = 1, R = x;
    while (R <= n) {
        pair<int, int> p = qry(1,1,n,L,R);
        if (p.first == p.second) return true;
        L++; R++;
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    int L = 2, R = n, mx = 1;
    while (L <= R) {
        int mid = (L + R)/2;
        if (check(mid)) L = mid + 1, mx = max(mx, mid);
        else R = mid - 1;
    }
    
    if (mx == 1) {
        cout << n << " " << 0 << endl;
        for (int i = 1; i <= n; i++) cout << i << " "; cout << endl;
        return;
    }
    vi res;
    L = 1, R = mx;
    while (R <= n) {
        pair<int, int> p = qry(1,1,n,L,R);
        if (p.first == p.second) res.pb(L);
        L++;R++;
    }
    cout << res.size() << " " << mx-1 << endl;
    debug(res);
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