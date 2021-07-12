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

const lli INF = 1e9-1, MOD = 998244353;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/problemset/problem/1472/E

bool cmp(vi a, vi b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
}

void solve () {
    int n; cin >> n;
    vector<vi> arr;
    vi res(n);
    for (int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        if (h > w) swap(h, w);
        arr.pb({h, w, i});
    }
    sort(arr.begin(), arr.end(), cmp);
    int ind = 0;
    res[arr[ind][2]] = -2;
    for (int i = 1; i < n; i++) {
        if (arr[ind][0] < arr[i][0] && arr[ind][1] < arr[i][1]) res[arr[i][2]] = arr[ind][2];
        else res[arr[i][2]] = -2;
        if (arr[i][1] < arr[ind][1]) ind = i;
    }
    for (int i: res) cout << i+1 << " "; cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    while (t--) solve();
}