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

const lli INF = 1e9-1, MOD = 1e9+7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1438/problem/D

void solve () {
    int n; cin >> n;
    bool ok = false;

    int arr[n], X = 0;
    for (int i = 0; i < n; i++) cin >> arr[i], X ^= arr[i];
    sort(arr, arr+n);
    vector<vi> res;

    if (n%2 == 0) {
        if (X != 0) ok = false;
        else {
            for (int i = 0; i < n-1; i+=2) {
                int a = i, b = i+1, c = i+2;
                if (a < n && b < n && c < n) {
                    int x = arr[a]^arr[b]^arr[c];
                    arr[a] = arr[b] = arr[c] = x;
                    res.pb({a+1,b+1,c+1});    
                }
            }
            for (int i = n-4; i >= 0; i-=2) {
                int a = i, b = i-1, c = i-2;
                if (a >= 0 && b >= 0 && c >= 0) {
                    int x = arr[a]^arr[b]^arr[c];
                    arr[a] = arr[b] = arr[c] = x;
                    res.pb({a+1,b+1,c+1});    
                }
            }
            if (arr[0] == arr[n-1]) ok = true;
            else ok = false;
        }
    } else {
        ok = true;
        for (int i = 0; i < n; i+=2) {
            int a = i, b = i+1, c = i+2;
            if (a < n && b < n && c < n) {
                int x = arr[a]^arr[b]^arr[c];
                arr[a] = arr[b] = arr[c] = x;
                res.pb({a+1,b+1,c+1});    
            }
        }
        for (int i = n-3; i >= 0; i-=2) {
            int a = i, b = i-1, c = i-2;
            if (a >= 0 && b >= 0 && c >= 0) {
                int x = arr[a]^arr[b]^arr[c];
                arr[a] = arr[b] = arr[c] = x;
                res.pb({a+1,b+1,c+1});    
            }
        }
    } 
    if (ok) {
        cout << "YES\n" << (int) res.size() << endl;
        for (vi i: res) debug(i);
        //for (int i: arr) cout << i << " "; 
    } else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    while (t--) solve();
}