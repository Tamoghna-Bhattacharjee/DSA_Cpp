#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 998244353;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://practice.geeksforgeeks.org/problems/reversal-algorithm5340/1

void logDAlgo(vi arr, int n, int d) {
    int st = 0, cn = n;
    while (d > 0 && st+d < n) {
        int i = st, j = i+d;
        while (j < n) {
            swap(arr[i], arr[j]);
            i++; j++;
        }
        st = i;
        d = d - (cn%d);
        cn = n-st;
    }
    debug(arr);
}

void ReversalAlgo(vi arr, int n, int d) {
    // arr = A[0...d-1] + B[d...n-1]
    // arr = ((A^-1)(B^-1))^-1
    //A^-1
    int i = 0, j = d-1;
    while (i < j) swap(arr[i], arr[j]), i++, j--;
    // B^-1
    i = d; j = n-1;
    while (i < j) swap(arr[i], arr[j]), i++, j--;
    //((A^-1)(B^-1))^-1
    i = 0, j = n-1;
    while (i < j) swap(arr[i], arr[j]), i++, j--;
    debug(arr);
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    for (int &i: arr) cin >> i;
    int d; cin >> d;
    ReversalAlgo(arr, n, d);
    logDAlgo(arr, n, d);
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