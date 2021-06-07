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
const int N = 3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1535/problem/E

lli a[N+1], c[N+1], p[N+1][20];

lli getFurthestParent(int u) {
    lli res = u;
    while (a[u] > 0) {
        res = u;
        bool found = false;
        for (int i = 19; i >= 0 && !found; i--) {
            if (p[u][i] != -1) {
                if (a[p[u][i]] > 0) {
                    u = p[u][i];
                    found = true;
                }
            }
        }
        if (!found) break;
    }
    return res;
}

pair<lli, lli> f(lli v, lli w) {
    lli res = 0, cnt = 0;
    while (w > 0) {
        lli u = getFurthestParent(v); // u is the furthest parent of v such that a[u] > 0
        lli taken = min(a[u], w);
        a[u] -= taken; w -= taken;
        cnt += taken;
        res += taken * c[u];
        if (u == v) break;
    }
    return {cnt, res};
}

void solve() {
    memset(p, -1, sizeof p);
    lli q; cin >> q >> a[0] >> c[0];
    for (int i = 1; i <= q; i++) {
        lli t; cin >> t;
        if (t == 1) {
            lli par, wt, cost; cin >> par >> wt >> cost;
            p[i][0] = par; a[i] = wt; c[i] = cost;
            for (int j = 1; j <= 19; j++) {
                if (p[i][j-1] != -1) p[i][j] = p[p[i][j-1]][j-1];
            }
        } else {
            lli v, w; cin >> v >> w;
            pair<lli, lli> res = f(v, w);
            cout << res.first << " " << res.second << endl;
        }
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