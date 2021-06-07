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
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/problemset/problem/339/D

int st[4*N+4], a[N+1];

char upd(int si, int ss, int se, int ui, int val) {
    if (ss == se) {
        a[ui] = val;
        st[si] = a[ss];
        return 'O';
    }
    int mid = (ss + se) / 2;
    char res = 'a';
    if (ui <= mid) res = upd(2*si, ss, mid, ui, val);
    else res = upd(2*si+1, mid+1, se, ui, val);
    if (res == 'O') {
        st[si] = st[2*si] | st[2*si+1];
        return 'X';
    } else {
        st[si] = st[2*si] ^ st[2*si+1];
        return 'O';
    }
}

void solve() {
    int n, m; cin >> n >> m;
    n = 1 << n;
    for (int i = 1; i <= n; i++) cin >> a[i], upd(1, 1, n, i, a[i]);
    while (m--) {
        int p, val; cin >> p >> val;
        upd(1, 1, n, p, val);
        cout << st[1] << endl;
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