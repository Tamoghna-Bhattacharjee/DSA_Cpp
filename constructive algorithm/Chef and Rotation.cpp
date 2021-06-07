#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back
// https://www.codechef.com/RC122020/problems/RECNDROT
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int arr[n];
        map<int, vi> mp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]].pb(i);
        }
        sort(arr, arr+n);
        int cnt = 1, l = mp[arr[0]][0];
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i-1]) continue;
            auto it = lower_bound(mp[arr[i]].begin(), mp[arr[i]].end(), l);
            if (it != mp[arr[i]].end()) {
                l = *it;
            }else {
                cnt++; l = mp[arr[i]][0];
            }
        }
        printf("%d\n", cnt);
    }
}
