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

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1430/problem/E

int arr[2*N], temp[2*N];

lli _merge(int L, int mid, int R) {
    int i = L, j = mid+1, k = L;
    lli inv = 0;
    while (i <= mid && j <= R) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            inv += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= R) temp[k++] = arr[j++];
    for (k = L; k <= R; k++) arr[k] = temp[k];
    return inv;
}

lli mergeSort(int L, int R) {
    if (L >= R) return 0;
    int mid = (L + R) / 2;
    lli inv1 = mergeSort(L, mid);
    lli inv2 = mergeSort(mid+1, R);
    lli m = _merge(L, mid, R);
    return inv1 + inv2 + m;
}

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    string revS = s; reverse(revS.begin(), revS.end());
    map<char, si> mp;
    for (int i = 0; i < n; i++) mp[s[i]].insert(i);
    for (int i = 0; i < n; i++) {
        arr[i] = *mp[revS[i]].begin(); 
        mp[revS[i]].erase(arr[i]);
    }
    lli ans = mergeSort(0, n-1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}