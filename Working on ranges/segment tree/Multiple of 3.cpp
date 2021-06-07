#include <bits/stdc++.h>
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

using namespace std;
// https://www.codechef.com/problems/MULTQ3
// hello_world10 -> AC  but  tamoghna_99 -> TLE

const int N = 1e5;
int st[4*N+4][3], lazy[4*N+4];

void shift(int si) {
    int t1 = st[si][0], t2 = st[si][1], t3 = st[si][2];
    st[si][1] = t1; st[si][2] = t2; st[si][0] = t3;
}

void buildTree(int si, int ss, int se) {
    if (ss > se) return;
    if (ss == se) {
        st[si][0]++; return;
    }
    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid);
    buildTree(2*si+1, mid+1, se);
    st[si][0] = st[2*si][0] + st[2*si+1][0];
}

void update(int si, int ss, int se, int us, int ue) {
    if (us > ue) return;
    if (lazy[si] != 0) {
        for (int i = 0; i < lazy[si]; i++) shift(si);
        if (ss != se) {
            lazy[2*si] = (lazy[2*si] + lazy[si]) % 3;
            lazy[2*si+1] = (lazy[2*si+1] + lazy[si]) % 3;
        }
        lazy[si] = 0;
    }
    if ((ss > se) || (us > se) || (ue < ss)) return;
    if (ss >= us && se <= ue) {
        shift(si);
        if (ss != se) {
            lazy[2*si] = (lazy[2*si] + 1) % 3;
            lazy[2*si+1] = (lazy[2*si+1] + 1) % 3;
        }
        return;
    }
    int mid = (ss + se) / 2;
    update(2*si, ss, mid, us, ue);
    update(2*si + 1, mid+1, se, us, ue);
    st[si][0] = st[2*si][0] + st[2*si+1][0];
    st[si][1] = st[2*si][1] + st[2*si+1][1];
    st[si][2] = st[2*si][2] + st[2*si+1][2];
}
int query(int si, int ss, int se, int qs, int qe) {
    if (qs > qe) return 0;
    if (lazy[si] != 0) {
        for (int i = 0; i < lazy[si]; i++) shift(si);
        if (ss != se) {
            lazy[2*si] = (lazy[2*si] + lazy[si]) % 3;
            lazy[2*si+1] = (lazy[2*si+1] + lazy[si]) % 3;
        }
        lazy[si] = 0;
    }
    if (ss > se || qs > se || qe < ss) return 0;
    if (ss >= qs && se <= qe) return st[si][0];
    int mid = (ss + se)/2;
    int l = query(2*si, ss, mid, qs, qe);
    int r = query(2*si+1, mid+1, se, qs, qe);
    return l+r;   
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q, a, b, ty;
    cin >> n >> q;
    buildTree(1, 1, n);
    while (q--) {
        cin >> ty >> a >> b; a++; b++;
        if (ty == 0) update(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << endl;
    }
}
