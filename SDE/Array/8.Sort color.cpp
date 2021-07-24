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
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://leetcode.com/problems/sort-colors/submissions/
// array consists of 0,1,2. Sort the array in linear time
// Sol-1: Dutch National Flag Algo: O(N)
// idea - [0 .... L-1] will contain 0
//        [L ... mid-1] will be 1
//        [R+1 ... n-1] will be 2      
// Sol-2: also there is a solution by calculating freq of each element and make the array: O(2*N)     

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int &i: a) cin >> i;
    int L = 0, R = n-1, mid = 0;
    while (mid <= R) {
        if (a[mid] == 0) swap(a[L], a[mid]), L++, mid++;
        else if (a[mid] == 1) mid++;
        else swap(a[R], a[mid]), R--;
    }
    debug(a);
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