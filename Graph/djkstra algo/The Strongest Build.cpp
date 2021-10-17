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
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 998244353;
const int N = 2e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// https://codeforces.com/contest/1574/problem/D

void solve() {
    int n; cin >> n;
    vi c(n);
    vector<vlli> a;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        vlli temp(c[i]);
        for (lli &i: temp) cin >> i;
        a.pb(temp);
    }
    set<vi> ban;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        vi b(n);
        for (int &i: b) cin >> i, i--;
        ban.insert(b);
    }
    set<pair<lli, vi>> s;
    {
        lli sum = 0;
        vi temp;
        for (int i = 0; i < n; i++) {
            temp.pb(c[i]-1);
            sum += a[i].back();
        }
        s.insert({sum, temp});
    }
    while (1) {
        auto cur = *s.rbegin();
        s.erase(cur);
        lli sum = cur.first;
        vi b = cur.second;
        if (ban.find(b) == ban.end()) {
            for (int i: b) cout << i+1 << " "; cout << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                lli ss = sum - a[i][b[i]] + a[i][b[i]-1];
                b[i]--;
                s.insert({ss, b});
                b[i]++;
            }
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