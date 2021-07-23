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

const lli INF = 1e9, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

vi mkLIS(vi &arr) {
    vi tail;
    map<int, int> parent;
    for (int i: arr) {
        auto pos = lower_bound(tail.begin(), tail.end(), i);
        if (pos == tail.end()) {
            if ((int) tail.size() == 0) parent[i] = INT_MAX;
            else parent[i] = tail.back();
            tail.pb(i);
        } else {
            if (pos == tail.begin()) parent[i] = INT_MAX;
            else parent[i] = *prev(pos);
            *pos = i;
        }
    }
    int len = (int) tail.size();
    vi LIS(len);
    int k = tail.back(), ind = len-1;
    while (k != INT_MAX) {
        LIS[ind--] = k;
        k = parent[k];
    }
    return LIS;
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vi LIS = mkLIS(arr);
    cout << "Size of LIS = " << (int) LIS.size() << endl;
    debug(LIS);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}