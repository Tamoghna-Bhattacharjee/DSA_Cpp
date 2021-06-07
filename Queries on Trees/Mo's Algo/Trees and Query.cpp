#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/375/problem/D

const int maxN = 1e5, BLK = 333;
int col[maxN+1], FT[2*maxN+2], in[maxN+1], out[maxN+1], t = 1;
int ans[maxN+1], freq[maxN+1], suf[2*maxN+2];
vi g[maxN+1];

struct Query {
    int l, r, block, ind, least;
    Query() {}
    Query(int _l, int _r, int _least, int _ind) {
        l = _l; r = _r; least = _least; ind = _ind;
        block = l/BLK;
    }
    bool operator < (const Query &b) const{
		if(block != b.block)
			return block < b.block;
		return r < b.r;
	}
} q[maxN+1];

void upd(int vtx, int op) {
    if (op == 1) {
        freq[col[vtx]]++; 
        suf[freq[col[vtx]]]++;
    }else {
        suf[freq[col[vtx]]]--;
        freq[col[vtx]]--;
    }
}

void moAlgo(int m) {
    int ML = 0, MR = -1;
    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r, least = q[i].least, ind = q[i].ind;
        // add
        while (ML > l) upd(FT[--ML], 1);
        while (MR < r) upd(FT[++MR], 1);
        // remove
        while (ML < l) upd(FT[ML++], -1);
        while (MR > r) upd(FT[MR--], -1);
        ans[ind] = suf[2*least];
    }
}

void dfs(int u, int p) {
    in[u] = t; FT[t] = u;
    t++;
    for (int v: g[u])
        if (v != p) dfs(v, u);
    out[u] = t; FT[t] = u;
    t++;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 0; i < n-1; i++) cin >> a >> b, g[a].pb(b), g[b].pb(a);
    t = 1;
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        q[i] = Query(in[a], out[a], b, i);
    }
    sort(q, q+m);
    moAlgo(m);
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}