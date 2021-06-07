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

// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// if the number is from 1..n then you can make the number at the corresponding element to be -ve
// if you encounter an index which is already negeted then the corresponding number is repeating.
// at last one index would remain +ve and that will be the missing number. 


void findMissingRepeating(vi &a, int n) {
    int X = 0;
    for (int i = 1; i <= n; i++) X ^= i, X ^= a[i-1];
    int F = 1 << (int) log2(X); // X = x^y;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if ((F&i) == 0) x ^= i;
        else y ^= i;
    }
    for (int i = 0; i < n; i++) {
        if ((a[i] & F) == 0) x ^= a[i];
        else y ^= a[i];
    }
    int missing = 0, repeating = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            missing = y; repeating = x; break;
        } else if (a[i] == y) { 
            missing = x; repeating = y; break;
        }
    }
    cout << missing << " " << repeating << endl;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int &i: a) cin >> i;
    findMissingRepeating(a, n);
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