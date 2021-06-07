#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

// https://www.spoj.com/problems/GOT/

const int N = 1e5, BLK = 333;
int val[N+1], freqN[N+1], freqV[N+1], in[N+1], out[N+1], FT[2*N+2], timer;
int LCA[N+1][21], level[N+1];
bool ans[2*N+2];
vi g[N+1];

struct Query {
    int l, r, ind, block, lca, c;
    Query(){}
    Query(int _l, int _r, int _c, int _lca, int i) {
        l = _l; r = _r; c = _c; lca = _lca, ind = i;
        block = l / BLK;
    } 
    bool operator < (const Query &b) const {
        if (block != b.block) return block < b.block;
        return r < b.r;
    }
} q[2*N+2];

void upd(int node, int op) {
    freqN[node] += op;
    if (op == 1) {
        if (freqN[node] == 1) freqV[val[node]]++;
        else freqV[val[node]]--;
    }else {
        if (freqN[node] == 1) freqV[val[node]]++;
        else freqV[val[node]]--;
    }
}

void moalgo(int m) {
    int ML = 0, MR = -1;
    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r, ind = q[i].ind, lca = q[i].lca, c = q[i].c;
        //add
        while (ML > l) upd(FT[--ML], 1);
        while (MR < r) upd(FT[++MR], 1);
        //remove
        while (ML < l) upd(FT[ML++], -1);
        while (MR > r) upd(FT[MR--], -1); 
        if (freqV[c] > 0) ans[ind] = true;
        if ((lca != -1) && (val[lca] == c)) ans[ind] = true;
    }
}

int getLCA(int a, int b) {
    if (level[a] > level[b]) swap(a,b);
    int d = level[b] - level[a];
    while (d > 0) {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }
    if (a == b) return a;
    for (int i = 20; i >= 0; i--) 
        if ((LCA[a][i] != -1) && (LCA[a][i] != LCA[b][i])) a = LCA[a][i], b = LCA[b][i];
    return LCA[a][0];
}

void mkLCA(int n) {
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n; i++) 
            if (LCA[i][j-1] != -1) LCA[i][j] = LCA[LCA[i][j-1]][j-1];
    }
}

void dfs(int u, int p) {
    level[u] = level[p]+1;
    LCA[u][0] = p;
    in[u] = timer; FT[timer] = u; timer++;
    for (int v: g[u])
        if (v != p) dfs(v, u);
    out[u] = timer; FT[timer] = u; timer++;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m, a, b, c;
    while (cin >> n) {
        cin >> m;
        for (int i = 0; i <= n; i++) {
            g[i].clear(), freqV[i] = 0, freqN[i] = 0, val[i] = 0;
            for (int j = 0; j < 21; j++) LCA[i][j] = -1;
        }
        for (int i = 1; i <= n; i++) cin >> val[i];
        for (int i = 0; i < n-1; i++) cin >> a >> b, g[a].pb(b), g[b].pb(a);
        timer = 1;
        dfs(1, 0);
        mkLCA(n);
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            if (in[a] > in[b]) swap(a, b);
            int lca = getLCA(a, b);
            if (lca == a) q[i] = Query(in[a], in[b], c, -1, i);
            else q[i] = Query(out[a], in[b], c, lca, i);
            ans[i] = false;
        }
        sort(q, q+m);
        moalgo(m);
        for (int i = 0; i < m; i++) cout << (ans[i]? "Find\n": "NotFind\n");
    }
}
