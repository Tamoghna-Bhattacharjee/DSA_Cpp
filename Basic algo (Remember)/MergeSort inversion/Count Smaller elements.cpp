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

// https://practice.geeksforgeeks.org/problems/count-smaller-elements2214/1/

// count the number of elements smaller than arr[i] in the range [i+1 ... n]

vi res, arr;
vector<pair<int, int>> a, temp;
    
void merge(int L, int mid, int R) {
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R) {
        if (a[i].first <= a[j].first) temp[k++] = a[i++];
        else {
            res[a[j].second] += mid - i + 1;
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= R) temp[k++] = a[j++];
    for (k = L; k <= R; k++) a[k] = temp[k];
}
    
void mergeSort(int L, int R) {
    if (L >= R) return;
    int mid = (L + R) / 2;
    mergeSort(L, mid);
    mergeSort(mid+1, R);
    merge(L, mid, R);
}

void solve () {
    int n; cin >> n;
    arr = vi(n); for (int &i: arr) cin >> i; 
    res = vi(n);
    temp = vector<pair<int, int>>(n);
    a = vector<pair<int, int>>(n);
    for (int i = 0, j = n-1; i < n; i++, j--) a[i] = {-arr[j], j};
    mergeSort(0, n-1);
    for (int i: res) cout << i << " "; cout << endl;
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