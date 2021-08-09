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
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://codeforces.com/contest/1555/problem/E

int st[4*N+4], lazy[4*N+4];

void rupd(int si, int ss, int se, int us, int ue, int diff) {
    if (us > ue) return;
    if (lazy[si] != 0) {
        st[si] += lazy[si];
        if (ss != se) {
            lazy[2*si + 1] += lazy[si];
            lazy[2*si] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (us > se || ue < ss || ss > se) return;
    if (ss >= us && se <= ue) {
        st[si] += diff;
        if (ss != se) {
            lazy[2*si + 1] += diff;
            lazy[2*si] += diff;
        }
        return;
    }
    int mid = (ss + se) / 2;
    rupd(2*si, ss, mid, us, ue, diff);
    rupd(2*si+1, mid+1, se, us, ue, diff);
    st[si] = min(st[2*si] , st[2*si + 1]);
}  
int qry(int si, int ss, int se, int qs, int qe) {
    if (lazy[si] != 0) {
        st[si] += lazy[si];
        if (ss != se) {
            lazy[2*si + 1] += lazy[si];
            lazy[2*si] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (qs > se || qe < ss || ss > se) return INT_MAX;
    if (ss >= qs && se <= qe) return st[si];
    int mid = (ss + se)/2;
    lli l = qry(2*si, ss, mid, qs, qe);
    lli r = qry(2*si+1, mid+1, se, qs, qe);
    return min(l,r);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> v;
    for (int i = 0; i < n; i++) {
        int l,r,w; cin >> l >> r >> w;
        v.pb({w,l,r-1});
    }
    sort(v.begin(), v.end());
    int L = 0, R = 0, ans = INT_MAX;
    while (L < n) {
        if (R == L) rupd(1,1,N,v[R][1],v[R][2],1), R++;
        while (R < n && qry(1,1,N,1,m-1) == 0) rupd(1,1,N,v[R][1],v[R][2],1), R++;
        if (qry(1,1,N,1,m-1) == 0) {
            L++; continue;
        }
        while (L <= R && qry(1,1,N,1,m-1) > 0) {
            ans = min(ans, v[R-1][0] - v[L][0]);
            rupd(1,1,N,v[L][1],v[L][2],-1), L++;
        }
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
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}