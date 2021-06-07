#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

//https://www.spoj.com/problems/MKTHNUM/

const int N = 1e5, M = 5000;
int arr[N+1];
vi st[4*N+4];
pair<int, int> B[N+1];

int query(int si, int ss, int se, int qs, int qe, int k) {
    if (ss == se) {
        return st[si][0];
    }
    int p = upper_bound(st[2*si].begin(), st[2*si].end(), qe) - lower_bound(st[2*si].begin(), st[2*si].end(), qs);
    int mid = (ss + se) / 2;
    if (p >= k) return query(2*si, ss, mid, qs, qe, k);
    else return query(2*si+1, mid+1, se, qs, qe, k-p);
}

void buildTree(int si, int ss, int se) {
    if (ss > se) return;
    if (ss == se) {
        st[si].pb(B[ss].second);
        return;
    }
    int mid = (ss + se) / 2;
    buildTree(2*si, ss, mid);
    buildTree(2*si + 1, mid+1, se);
    merge(st[2*si].begin(), st[2*si].end(), st[2*si+1].begin(), st[2*si+1].end(), back_inserter(st[si]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l, r, k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        B[i] = {arr[i], i};
    }
    sort(B+1, B+n+1);
    buildTree(1, 1, n);
    while (m--) {
        cin >> l >> r >> k;
        cout << arr[query(1, 1, n, l, r, k)] << endl;
    }
}
