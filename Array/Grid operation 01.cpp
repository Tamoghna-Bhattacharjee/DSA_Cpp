#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1371/problem/D

void solve() {
    int n, k; cin >> n >> k;
    int arr[n][n];
    memset(arr, 0, 4*n*n);
    for (int currLen = 1; currLen <= n && k; currLen++) {
        for (int i = 0; i < n-currLen+1 && k; i++) {
            int j = i + currLen - 1;
            arr[i][j] = 1; k--;
        }
        
        for (int i = n-1; i >= n-currLen+1 && k; i--) {
            int j = i+currLen-(n+1);
            arr[i][j] = 1; k--;
        }
        
    }
    int mxR = INT_MIN, miR = INT_MAX;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += arr[i][j];
        mxR = max(mxR, sum);
        miR = min(miR, sum);
    }
    int mxC = INT_MIN, miC = INT_MAX;
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i][j];
        mxC = max(mxC, sum);
        miC = min(miC, sum);
    }
    int F = (mxR - miR) * (mxR - miR) + (mxC - miC) * (mxC - miC);
    cout << F << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << arr[i][j];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
    