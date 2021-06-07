#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back
/*
 https://www.spoj.com/problems/KQUERY/

Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) 
(1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the 
subsequence ai, ai+1, ..., aj.
*/

// precomputing -> O(n*log(n));
// query -> O(q * log(n) * log(n))

const int N = 30000;
int arr[N+1];
vi st[4*N+4];

int query(int si, int ss, int se, int qs, int qe, int k) {
    if ((qs > se) || (qe < ss) || (ss > se)) return 0;
    if ((ss >= qs) && (se <= qe)) {
        return st[si].size() - (upper_bound(st[si].begin(), st[si].end(), k) - st[si].begin());
    }
    int mid = (ss+se) / 2;
    int l = query(2*si, ss, mid, qs, qe, k);
    int r = query(2*si + 1, mid+1, se, qs, qe, k);
    return l+r;
}

vi merge(vi &v1, vi &v2) {
    int i = 0, j = 0;
    vi temp;
    while ((i < v1.size()) && (j < v2.size())) {
        if (v1[i] < v2[j]) temp.pb(v1[i++]);
        else temp.pb(v2[j++]); 
    }
    while (i < v1.size()) temp.pb(v1[i++]);
    while (j < v2.size()) temp.pb(v2[j++]);
    return temp;
}

void buildTree(int si, int ss, int se) {
    if (ss > se) return;
    if (ss == se) {
        st[si].pb(arr[ss]); return;
    }
    int mid = (ss + se) / 2;
    buildTree(2*si, ss, mid);
    buildTree(2*si + 1, mid+1, se);
    st[si] = merge(st[2*si], st[2*si+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, l, r, k;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    buildTree(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
    }
}
