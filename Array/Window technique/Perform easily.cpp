#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18-1, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1435/problem/C

lli a[6]; 
int n, cnt = 0;
int visit[N+5];

void ins(int x) {
    if (visit[x] == 0) cnt++;
    visit[x]++;
}

void del(int x) {
    visit[x]--;
    if (visit[x] == 0) cnt--;
}

void solve() {
    for (int i = 0; i < 6; i++) cin >> a[i];
    cin >> n;
    vector<pair<lli, int>> v;
    for (int i = 0; i < n; i++) {
        lli val; cin >> val;
        for (int j = 0; j < 6; j++) v.pb({val - a[j], i});
    }
    sort(v.begin(), v.end());
    int l = 0, r = 0;
    lli ans = INF;
    while (l < 6*n) {
        while (r < 6*n && cnt < n) ins(v[r].second), r++;
        if (cnt == n) ans = min(ans, v[r-1].first - v[l].first);
        del(v[l].second); l++;
    }
    cout << ans << endl;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}