#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define MOD 1000000007
#define pb push_back

// https://www.spoj.com/problems/RANGESUM/

const int N = 1e5;
lli arr[N+1], extra[N+5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, l, r, op, x; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cin >> q;
    int ind = 0;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            //cout << " ans = ";
            if (ind < l) cout << (arr[r-ind] - arr[l-ind-1]) << endl;
            else if (ind >= r) {
                r = ind - r +1, l = ind - l + 1;
                swap(l, r);
                cout << (extra[r] - extra[l-1]) << endl;
            } else {
                cout << (extra[ind-l+1] + arr[r-ind]) << endl;
            }
        }else {
            cin >> x;
            extra[++ind] = x; extra[ind] += extra[ind-1];
        }
    }
}