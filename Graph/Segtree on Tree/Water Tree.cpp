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

// https://codeforces.com/contest/343/problem/D

int n, tmr = 1;
vi g[N+1], st, lazy, in, out, par;

void rupd(int si, int ss, int se, int us, int ue, lli x) {
    if (us > ue) return;
    if (lazy[si] != -1) {
        st[si] = lazy[si];
        if (ss != se) {
            lazy[2*si + 1] = lazy[si];
            lazy[2*si] = lazy[si];
        }
        lazy[si] = -1;
    }
    if (us > se || ue < ss || ss > se) return;
    if (ss >= us && se <= ue) {
        st[si] = x;
        if (ss != se) {
            lazy[2*si + 1] = x;
            lazy[2*si] = x;
        }
        return;
    }
    int mid = (ss + se) / 2;
    rupd(2*si, ss, mid, us, ue, x);
    rupd(2*si+1, mid+1, se, us, ue, x);
    st[si] = st[2*si] & st[2*si + 1];
}   

lli qry(int si, int ss, int se, int qs, int qe) {
    if (lazy[si] != -1) {
        st[si] = lazy[si];
        if (ss != se) {
            lazy[2*si + 1] = lazy[si];
            lazy[2*si] = lazy[si];
        }
        lazy[si] = -1;
    }
    if (qs > se || qe < ss || ss > se) return INT_MAX;
    if (ss >= qs && se <= qe) return st[si];
    int mid = (ss + se)/2;
    lli l = qry(2*si, ss, mid, qs, qe);
    lli r = qry(2*si+1, mid+1, se, qs, qe);
    return min(l,r);
}

void dfs(int u, int p) {
    in[u] = tmr++;
    par[u] = p;
    for (int v: g[u]) {
        if (v != p) dfs(v,u);
    }
    out[u] = tmr++;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    st = vi(8*n+8); lazy = vi(8*n+8, -1);
    in = vi(n+1); out = vi(n+1); 
    par = vi(n+1);
    dfs(1,-1);
    tmr--;
    int q; cin >> q;
    while (q--) {
        int t, u; cin >> t >> u;
        if (t == 1) {
            if (qry(1, 1, tmr, in[u], out[u]) != 1 && par[u] != -1) {
                // if any of the node in subtree of u is empty, then all the ancester of 
                // u is also empty
                rupd(1,1,tmr,in[par[u]], in[par[u]], 0), rupd(1,1,tmr,out[par[u]], out[par[u]], 0);
            }
            rupd(1, 1, tmr, in[u], out[u], 1);
        } else if (t == 2) rupd(1,1,tmr,in[u], in[u], 0), rupd(1,1,tmr,out[u], out[u], 0);
        else cout << qry(1, 1, tmr, in[u], out[u])<< endl;
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