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
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e9-1, MOD = 1e9 + 7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1466/problem/E

void solve() {
    int n; cin >> n;
    lli a[n], bitCnt[60];
    memset(bitCnt, 0, sizeof bitCnt);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (lli j = 59; j >= 0; j--) {
            lli F = (1LL << j);
            if ((F&a[i]) != 0) bitCnt[j]++;
        }
    }

    lli ans = 0;
    for (lli i: a) {
        lli _or = 0, _and = 0;
        for (lli j = 0; j <= 59; j++) {
            if ((i & (1LL << j)) == 0) {
                _or = (_or + 1LL * (1LL << j) % MOD * bitCnt[j] % MOD) % MOD;
            } else {
                _or = (_or + 1LL * (1LL << j) % MOD * n% MOD) % MOD;
                _and = (_and + 1LL * (1LL << j) % MOD * bitCnt[j] % MOD) % MOD; 
            }
        }
        ans = (ans + 1LL * _or * _and % MOD) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    while (t--) solve();
}