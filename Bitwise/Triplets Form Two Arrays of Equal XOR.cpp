#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back   
const lli INF = 1e18-1, MOD = 998244353;
const int N = 1e5;

// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i < n; i++) arr[i] ^= arr[i-1];   
    map<int, vector<int>> mp;
    mp[0].pb(-1);
    for (int i = 0; i < n; i++) mp[arr[i]].pb(i);

    lli cnt = 0;
    for (auto it: mp) {
        vector<int> inds = it.second;
        int len = (int) inds.size();
        if (len > 1) {
            int posCoef = 0, negCoef = len-1;
            for (int i = 0; i < len; i++, posCoef++, negCoef--) 
                cnt += (posCoef * inds[i] - negCoef * inds[i]) * 1LL;
            cnt -= len * (len - 1) / 2;
            /*
            (i1, i2, i3, i4) -> (i2-i1-1) + (i3-i1-1) + (i4-i1-1) + (i3-i2-1) + (i4-i2-1) + (i4-i3-1)
                            = (i2+i3+i4) + (i3+i4) + i4 - 3*i1 - 2*i2 - i3 - 6
                            = 0*i1 + 1*i2 + 2*i3 + 3*i4 - 3*i1 - 2*i2 - i3 - 0*i4 - 4*(4-1)/2;
            */
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}