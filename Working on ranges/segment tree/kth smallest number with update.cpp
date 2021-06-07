#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

const int N = 1e6;
int st[4*N+4], lazy[4*N+4]; // seg tree of freq sum

/*
void update(int si, int ss, int se, int ui, int type) {
    if (ss > se) return;
    if (ss == se) {
        st[si] += type;
        return;
    }
    int mid = (ss + se) / 2;
    if (ui <= mid) update(2*si, ss, mid, ui, type);
    else update(2*si+1, mid+1, se, ui, type); 
    st[si] = st[2*si] + st[2*si+1];
}
int query(int si, int ss, int se, int qs, int qe) {
    if ((ss > se) || (qs > se) || (qe < ss)) return 0;
    if ((ss >= qs) && (se <= qe)) return st[si];
    int mid = (ss + se) / 2;
    int l = query(2*si, ss, mid, qs, qe);
    int r = query(2*si+1, mid+1, se, qs, qe);
    return l+r;
}
*/

void update(int si, int ss, int se, int us, int ue, int type) {
    if (us > ue) return;
    if (lazy[si] != 0) {
        st[si] += lazy[si];
        if (ss != se) {
            lazy[2*si] += lazy[si]; 
            lazy[2*si+1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if ((ss > se) || (ue < ss) || (us > se)) return;
    if ((ss >= us) && (se <= ue)) {
        st[si] += type;
        if (ss != se) {
            lazy[2*si] += type;
            lazy[2*si+1] += type;
        }
        return;
    }
    int mid = (ss + se) / 2;
    update(2*si, ss, mid, us, ue, type);
    update(2*si+1, mid+1, se, us, ue, type);
    st[si] = st[2*si] + st[2*si+1];
}

int query(int si, int ss, int se, int qi) {
    if (ss > se) return 0;
    if (lazy[si] != 0) {
        st[si] += lazy[si];
        if (ss != se) {
            lazy[2*si] += lazy[si]; 
            lazy[2*si+1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss == se) return st[si];
    int mid = (ss + se) / 2;
    if (qi <= mid) return query(2*si, ss, mid, qi);
    else return query(2*si+1, mid+1, se, qi);
}

void solve() {
    int n, q, x, k;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> x, update(1, 1, n, x, n, 1);
    // inserting a number
    // removing kth smallest element

    // intuition in finding kth smallest element 
    // -> do binary search in a range [1, n]
    // -> check the prefix sum of freq of mid element where mid = (L+R)/2
    //              -> if its >= k: then it may be an ans and reduce range to [L, mid-1]
    // -> else reduce the range [mid+1, R]

    while (q--) {
        cin >> k;
        // inserting a number O(1)
        if (k > 0) update(1, 1, n, k, n, 1);
        else {
            // kth smallest number O(log(n) * log(n))
            k = -k;
            int L = 1, R = n, ans = 0;
            while (L <= R) {
                int mid = (L + R) / 2;
                int x = query(1, 1, n, mid), y = query(1, 1, n, mid-1);
                if ((x >= k) && (y < k)) {
                    ans = mid; break;
                }
                if (x >= k) R = mid-1;
                else L = mid+1;
            }
            update(1, 1, n, ans, n, -1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (query(1, 1, n, i) > 0) {
            res = i;
            break;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}