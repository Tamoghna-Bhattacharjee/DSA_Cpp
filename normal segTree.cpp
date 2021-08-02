#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
const int N = 1e3;
const string ans[] = {"NO", "YES"};

lli segTree[4*N+4], lazyProp[4*N+4], diff_arr[N+1][N+1];

void rupd(int si, int ss, int se, int us, int ue, lli diff) {
    if (us > ue) return;
    if (lazyProp[si] != 0) {
        segTree[si] += (se - ss + 1) * lazyProp[si];
        if (ss != se) {
            lazyProp[2*si + 1] += lazyProp[si];
            lazyProp[2*si] += lazyProp[si];
        }
        lazyProp[si] = 0;
    }
    if (us > se || ue < ss || ss > se) return;
    if (ss >= us && se <= ue) {
        segTree[si] += (se - ss + 1) * diff;
        if (ss != se) {
            lazyProp[2*si + 1] += diff;
            lazyProp[2*si] += diff;
        }
        return;
    }
    int mid = (ss + se) / 2;
    rupd(2*si, ss, mid, us, ue, diff);
    rupd(2*si+1, mid+1, se, us, ue, diff);
    segTree[si] = segTree[2*si] + segTree[2*si + 1];
}   

lli qry(int si, int ss, int se, int qs, int qe) {
    if (lazyProp[si] != 0) {
        segTree[si] += (se - ss + 1) * lazyProp[si];
        if (ss != se) {
            lazyProp[2*si + 1] += lazyProp[si];
            lazyProp[2*si] += lazyProp[si];
        }
        lazyProp[si] = 0;
    }
    if (qs > se || qe < ss || ss > se) return 0;
    if (ss >= qs && se <= qe) return segTree[si];
    int mid = (ss + se)/2;
    lli l = qry(2*si, ss, mid, qs, qe);
    lli r = qry(2*si+1, mid+1, se, qs, qe);
    return l+r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
}