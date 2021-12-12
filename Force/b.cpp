#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 

template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 998244353;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

bool f1(int n, int a, int b) {
    vi arr(n+1);
    int L = 1, R = n, cnta = 0, cntb = 0;
    arr[1] = L++;
    int i = 2;
    while (i <= n && cnta < a && cntb < b) {
        if (i%2 == 0) arr[i++] = R, R--, cnta++;
        else arr[i++] = L, L++, cntb++;
    }
    if (i%2) {
        while (i <= n) {
            arr[i++] = L++;
        }
    } else {
        while (i <= n) arr[i++] = R--;
    }
    cnta = cntb = 0;
    for (int i = 2; i <= n-1; i++) {
        if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) cnta++;
        else if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) cntb++;
    }
    if (cnta == a && cntb == b) {
        for (int i = 1; i <= n; i++) cout << arr[i] << " "; cout << endl;
        return true;
    } else return false;
}

bool f2(int n, int a, int b) {
    vi arr(n+1);
    int L = 1, R = n, cnta = 0, cntb = 0;
    arr[1] = R--;
    int i = 2;
    while (i <= n && cnta < a && cntb < b) {
        if (i % 2 == 0) arr[i++] = L, L++, cntb++;
        else arr[i++] = R, R--, cnta++;
    }
    if (i%2) {
        while (i <= n) {
            arr[i++] = R--;
        }
    } else {
        while (i <= n) arr[i++] = L++;
    }
    cnta = cntb = 0;
    for (int i = 2; i <= n-1; i++) {
        if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) cnta++;
        else if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) cntb++;
    }
    if (cnta == a && cntb == b) {
        for (int i = 1; i <= n; i++) cout << arr[i] << " "; cout << endl;
        return true;
    } else return false;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (f1(n,a,b) || f2(n,a,b)) return;
    else cout << -1 << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}