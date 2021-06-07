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
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1513/problem/D

int findNode(vi &dsu, int x) {
    if (dsu[x] < 0) return x;
    return dsu[x] = findNode(dsu, dsu[x]);
}

bool unionNode(vi &dsu, int a, int b) {
    a = findNode(dsu, a), b = findNode(dsu, b);
    if (a == b) return false;
    if (dsu[a] <= dsu[b]) swap(a,b);
    dsu[b] += dsu[a];
    dsu[a] = b;
    return true;
}

void solve() {
    int n, p; cin >> n >> p;
    vi a(n+1), dsu(n+1, -1), visit(n+1);
    vpii temp;
    for (int i = 0; i < n; i++) cin >> a[i], temp.pb({a[i], i});
    sort(temp.begin(), temp.end());
    lli ans = 0;
    for (int k = 0; k < n; k++) {
        int g = temp[k].first, i = temp[k].second;
        if (g >= p) break;
        if (dsu[i] == -1) {
            for (int j = i-1; j >= 0; j--) {
                if (a[j] % g == 0) {
                    if (unionNode(dsu, i, j)) ans += g;
                    else break;
                } else break;
            }
            for (int j = i+1; j < n; j++) {
                if (a[j] % g == 0) {
                    if (unionNode(dsu, i, j)) ans += g;
                    else break;
                } else break;
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (unionNode(dsu, i,i+1)) ans += p;
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
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}