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
const int N = 1e7;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/problemset/problem/339/C

set<vi> states;
vi a, res;
int m, ok = 0;

void f(int diff, int prevWt, int cnt) {
    if (states.find({diff, prevWt, cnt}) != states.end()) return;
    if (cnt > m) {
        res.pb(prevWt);
        ok = 1; return;
    }
    for (int i: a) {
        if (i != prevWt) {
            if (cnt % 2 == 1 && diff+i > 0) f(diff + i, i, cnt+1);
            else if (cnt%2 == 0 && diff-i < 0) f(diff-i, i, cnt+1);
            if (ok) {
                res.pb(prevWt);
                return;
            }
        } 
    }
}

void solve() {
    string s; cin >> s; s = "#"+s;
    cin >> m;
    int n = (int) s.size();
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') a.pb(i);
    }
    
    f(0,0,1);
    cout << YN[ok] << endl;
    if (ok) {
        reverse(res.begin(), res.end());
        for (int i: res) {
            if (i!=0) cout << i << " ";
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