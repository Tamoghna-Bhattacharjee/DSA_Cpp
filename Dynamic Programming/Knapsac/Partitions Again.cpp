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
const int N = 3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1516/submission/113798474

int n, a[101];

bool knapsac(int x) {
    int dp[n+1][x+1]; memset(dp, 0, sizeof dp);
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-a[i] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j-a[i]];
        }
    }       
    return dp[n][x];
}

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum % 2) {
        cout << 0 << endl; return;
    }
    bool ok = knapsac(sum/2);
  
    if (!ok) {
        cout << 0 << endl; return;
    }

    for (int i = 1; i <= n && ok; i++) {
        int temp = a[i]; a[i] = 0;
        int x = sum - temp;
        if (x%2) {
            cout << 1 << endl << i << endl; return;
        } else if (!knapsac(x/2)) {
            cout << 1 << endl << i << endl; return;
        } else a[i] = temp;
    }
    cout << 0 << endl;
}  


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}