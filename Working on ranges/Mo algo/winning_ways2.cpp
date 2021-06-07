//https://www.codechef.com/problems/MDSWIN2
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 

const int maxN = 1e5, mod = 998244353, BLK = 300;
lli f1[maxN+1], f2[maxN+1], inv[maxN+1];
int arr[maxN+1], freq[maxN+1], cof[maxN+1], XOR = 0, ans[maxN+1];
bool toAdd[maxN+1];
vector<int> table;

struct Query {
    int l, r, ind, block;
    Query(){}
    Query(int _l, int _r, int _id) {
        l = _l, r = _r, ind = _id;
        block = _l/BLK;
    }
    bool operator < (const Query &b) const{
        if (block != b.block) return block < b.block;
        return r < b.r;
    }
} queries[maxN];

void fact() {
    inv[1] = 1;
    for (int i = 2; i <= maxN; i++) inv[i] = mod - mod/i*inv[mod%i]%mod;
    f1[0] = f2[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        f1[i] = f1[i-1]*i%mod;
        f2[i] = f2[i-1] * inv[i] % mod;
    }
}

void utd(int val, int op) {
    XOR ^= freq[val];
    cof[freq[val]]--;
    freq[val]+=op;
    cof[freq[val]]++;
    XOR ^= freq[val];
    if (!toAdd[freq[val]]) {
        toAdd[freq[val]] = true; table.push_back(freq[val]);
    }
}

void moalgo(int Q) {
    int ML = 0, MR = -1;
    for (int i = 0; i < Q; i++) {
        Query q = queries[i];
        int l = q.l, r = q.r, ind = q.ind;
        while (ML > l) ML--, utd(arr[ML], 1);
        while (MR < r) MR++, utd(arr[MR], 1);
        while (ML < l) utd(arr[ML], -1), ML++;
        while (MR > r) utd(arr[MR], -1), MR--;
        vector<int> temp;
        for (int n: table) {
            if (cof[n] == 0) {
                toAdd[n] = false; continue;
            }
            int x = XOR ^ n;
            if (x < n) {
                ans[ind] = (ans[ind] + cof[n]%mod*f1[n]%mod*f2[x]%mod*f2[n-x]%mod)%mod;
            }
            temp.push_back(n);
        }
        table = temp;
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    fact();
    int T, n, Q, l, r;
    cin>>T;
    while (T--) {
        cin>>n;
        map<int, int> mp;
    	for(int i=0; i<n; ++i) {
    		cin >> arr[i];
    		if(mp.find(arr[i])==mp.end()) mp.insert({arr[i], mp.size()});
    		arr[i]=mp[arr[i]];
    	}
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> l >> r;
            l--; r--;
            queries[i] = Query(l,r,i);
        }
        sort(queries, queries+Q);
        memset(freq, 0, 4*n); memset(ans, 0, 4*Q);
        memset(cof, 0, 4*n); memset(toAdd, 0, 4*n);
        XOR = 0;
        table = {};
        moalgo(Q);
        for (int i = 0; i < Q; i++) cout << ans[i] << endl;
    }
}
