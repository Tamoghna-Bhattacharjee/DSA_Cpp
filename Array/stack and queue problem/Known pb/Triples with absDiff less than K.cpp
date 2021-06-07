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
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://www.geeksforgeeks.org/triplets-array-absolute-difference-less-k/

void solve() { 
    /*
        Input
        n = 5, k = 1
        arr = {1, 1, 2, 2, 3,}
    */ 
    int n, k; cin >> n >> k;
    vi arr(n);
    for (int &i: arr) cin >> i;
    int ans = 0;
    sort(arr.begin(), arr.end());

    for (int i = 2; i < n; i++) {
        int L = lower_bound(arr.begin(), arr.end(), arr[i] - k) - arr.begin();
        int R = i-1;
        int len = R-L+1;
        if (len >= 2) ans = (ans + len * (len - 1) / 2) % MOD;
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) solve();
}