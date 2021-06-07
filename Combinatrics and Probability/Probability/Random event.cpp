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
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e9-1, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1461/problem/C

void solve() {
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, double>> e;
    for (int i = 0; i < m; i++) {
        int x; double p; cin >> x >> p;
        e.pb({x, p});
    }

    int cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == i+1) {
            cnt++; 
        } else break;
    }
    int req = n-cnt;
    if (req == 0) {
        cout << 1 << endl;
        return;
    }
    double negProb = 1, ans = 0;
    for (auto i: e) {
        int x = i.first; double p = i.second;
        if (x >= req) {
            ans += negProb * p;
            negProb *= (1-p);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    while (t--) solve();
}