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

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 2e5 + 5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1465/problem/D

void solve() {
    string s; cin >> s;
    int n = (int) s.size(); s = " " + s;
    lli x, y; cin >> x >> y;
    if (x > y) {
        swap(x, y);
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') s[i] = '1';
            else if (s[i] == '1') s[i] = '0';
        }
    }
    int pref[n+5][3], suf[n+5][3];
    memset(pref, 0, sizeof pref); memset(suf, 0, sizeof suf);
    for (int i = 1; i <= n; i++) {
        pref[i][0] = pref[i-1][0];
        pref[i][1] = pref[i-1][1];
        pref[i][2] = pref[i-1][2];
        if (s[i] == '?') pref[i][2]++;
        else pref[i][s[i] - '0']++;
    }

    for (int i = n; i >= 1; i--) {
        suf[i][0] = suf[i+1][0];
        suf[i][1] = suf[i+1][1];
        suf[i][2] = suf[i+1][2];
        if (s[i] == '?') suf[i][2]++;
        else suf[i][s[i] - 48]++;
    }
    
    lli ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1' || s[i] == '?') {
            cur += 1LL * x * pref[i][0];
        } else cur += 1LL * y * (pref[i][1] + pref[i][2]);
    }
    ans = cur;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') {
            cur -= 1LL * x * pref[i][0];
            cur -= 1LL * y * suf[i][0];
            cur += 1LL * y * pref[i][1];
            cur += 1LL * x * suf[i][1];
            cur -= 1LL * x * pref[i-1][2];
            cur += 1LL * x * suf[i+1][2];
        }   
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

int main() {
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    while (t--) solve();
}