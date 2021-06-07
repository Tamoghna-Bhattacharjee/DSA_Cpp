//https://codeforces.com/contest/86/problem/D
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define pb push_back

const int maxN = 200000, BLK = 333;
int arr[maxN+1], freq[1000006];
lli ans[maxN+1], sum = 0;

struct Query {
    int l ,r, ind, block;
    Query() {}
    Query(int _l, int _r, int _ind) {
        l = _l; r = _r; ind = _ind;
        block = _l/BLK;
    }
    bool operator < (const Query &b) const {
        if (block != b.block) return block < b.block;
        return r < b.r;
    }
} queries[maxN+1];

void utd(int val, int op) {
    sum -= (lli)freq[val] * freq[val] * val;
    freq[val] += op;
    sum += (lli)freq[val] * freq[val] * val;
}

void moalgo(int Q) {
    int ML = 0, MR = -1;
    for (int i = 0; i < Q; i++) {
        Query curr = queries[i];
        int l = curr.l, r = curr.r, ind = curr.ind;
        while (ML > l) utd(arr[--ML], 1);
        while (MR < r) utd(arr[++MR], 1);
        while (ML < l) utd(arr[ML++], -1);
        while (MR > r) utd(arr[MR--], -1);
        ans[ind] = sum;
    }
}

int main() {
    int n, Q, l, r;
    cin >> n >> Q;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        l--; r--;
        queries[i] = Query(l,r,i);
        ans[i] = 0;
    }
    sum = 0;
    sort(queries, queries+Q);
    moalgo(Q);
    for(int i = 0; i< Q; i++) printf("%I64d\n", ans[i]);
}