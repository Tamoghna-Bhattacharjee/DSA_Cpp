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

const int N = 200000;
lli a[N], b[N], x, k, y;
map<lli, int> mp;

// https://codeforces.com/contest/1380/problem/D

lli getMana(int L, int R, int n) {
    if (R-L == 1) return 0;
    if (L > R) return -1;
    lli leftM = L >= 0? a[L]: -1;
    lli rightM = R < n? a[R]: -1;
    int size = R-L-1;
    lli mx = *max_element(a+L+1, a+R);
    if (size < k) {
        if (mx < leftM || mx < rightM) return y*size;
        else return -1;
    } else {
        lli res = 0;
        lli rem = size % k;
        size -= rem;
        res += y*rem;
        if (k*y < x) {
            if (mx < leftM || mx < rightM) res += y*size;
            else res += (size-k)*y + x;
        } else res += x * (size/k);
        return res;
    }
}

lli solve() {
    int n, m; cin >> n >> m;
    cin >> x >> k >> y;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]] = i;
    for (int i = 0; i < m; i++) cin >> b[i];
    lli ans = 0;
    if (mp[b[0]] > 0) {
        lli z = getMana(-1, mp[b[0]], n); 
        if (z == -1) return -1;
        ans += z;
    }
    for (int i = 1; i < m; i++) {
        lli z = getMana(mp[b[i-1]], mp[b[i]], n);
        if (z == -1) return -1;
        ans += z;
    } 
    if (mp[b[m-1]] < n-1) {
        lli z = getMana(mp[b[m-1]], n, n);
        if (z == -1) return -1;
        ans += z;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1;
    while (t--) cout << solve() << endl;
}

