#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
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
const int N = 1e7;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1538/problem/G

lli x, y, a, b;

bool check(lli n) {
    lli L = 0, R = n;
    while (L <= R) {
        lli mid = (L + R) / 2;
        lli red = b*n + (a-b)*mid;
        lli blue = a*n + (b-a)*mid;
        if (red <= x && blue <= y) return true;
        else if (red > x && blue > y) return false;
        else if (red > x) {
            if (a >= b) R = mid - 1;
            else L = mid + 1; 
        } else {
            if (b >= a) R = mid - 1;
            else L = mid + 1;
        }
    }
    return false;
}

void solve() {
    cin >> x >> y >> a >> b;
    lli L = 0, R = 1e9;
    while (L <= R) {
        lli mid = (L + R)/2;
        if (check(mid)) L = mid + 1;
        else R = mid - 1;
    }
    cout << L-1 << endl;
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