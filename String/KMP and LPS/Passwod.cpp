#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/126/problem/B

void solve() {
    string s; cin >> s;
    int n = (int) s.size();
    vi LPS(n);
    int j = 0, i = 1;
    while (i < n) {
        if (s[i] == s[j]) {
            LPS[i] = j+1;
            j++; i++;
        } else {
            if (j == 0) LPS[i] = 0, i++;
            else j = LPS[j-1];
        }
    }
    vector<bool> isFound(n, false);
    for (int i = 1; i < n-1; i++) isFound[LPS[i]] = true; 
    
    j = LPS[n-1];
    while (j > 0) {
        if (isFound[j]) {
            cout << s.substr(0,j) << endl;
            return;
        }
        j=LPS[j-1];
    }
    cout << "Just a legend\n";
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
    for (int h = 1; h <= t; h++) {
        //cout << "Case #" << h << ": ";
        solve();
    }
}