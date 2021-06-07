#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

// To  calculate how many elemet  E <= k in range [l, r]

const int N = 30000, M = 2e5, BLK = 333;
int arr[N+1], freq[N+1], ans[M+1], B[BLK+1];

struct Query {
    int l, r, block, k, ind;
    Query() {}
    Query(int _l, int _r, int _k, int i) {
        l = _l; r = _r; k = _k; ind = i;
        block = l / BLK;
    }
    bool operator < (const Query &b) const {
        if (block != b.block) return block < b.block;
        return r < b.r;
    }
} q[M+1];


int getAns(int k) {
    // sqrt decomposition -> used to calculate => sum(freq[i]) for i in [0, k]; 
    int res = 0, LB = 0, RB = k/BLK;
    if (LB == RB) {
        for (int i = 0; i <= k; i++) res += freq[i];
    }else {
        for (int i = LB; i < RB; i++) res += B[i];
        for (int i = RB*BLK; i <= k; i++) res += freq[i];
    }
    return res;
}

void upd(int num, int op) {
    freq[num] += op;
    B[num/BLK] += op;
}

void moalgo(int m) {
    int ML = 0, MR = -1;
    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r, k = q[i].k, ind = q[i].ind;
        // add
        while (ML > l) upd(arr[--ML], 1);
        while (MR < r) upd(arr[++MR], 1);
        // remove
        while (ML < l) upd(arr[ML++], -1);
        while (MR > r) upd(arr[MR--], -1);
        
        ans[ind] = getAns(k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l, r, k;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> l >> r >> k, q[i] = Query(l, r, k, i);
    sort(q, q+m);
    moalgo(m);
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
}
