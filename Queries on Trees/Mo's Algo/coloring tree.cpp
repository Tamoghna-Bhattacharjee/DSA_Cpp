#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

// https://www.hackerrank.com/challenges/coloring-tree/problem

const int N = 1e5, BLK = 333;
int FT[2*N+1], in[N+1], out[N+1], freqV[N+1], col[N+1], timer = 1;
int ans[N+1], res = 0;
vi g[N+1];

struct Query {
    int l, r, block, ind;
    Query() {}
    Query(int _l, int _r, int i) {
        l = _l; r = _r; ind = i;
        block = l/BLK;
    }
    bool operator < (const Query &b) const {
        if (block != b.block) return block < b.block;
        return r < b.r;
    }
} q[N+1];

void dfs(int u, int p) {
    in[u] = timer; FT[timer] = u; timer++;
    for (int v: g[u]) 
        if (v != p) dfs(v, u);
    out[u] = timer; FT[timer] = u; timer++;
}

void upd(int vtx, int op) {
    if (op == 1) {
        if (++freqV[col[vtx]] == 1) res++;
    } else {
        if (freqV[col[vtx]]-- == 1) res--;
    }
}

void moalgo(int m) {
    int ML = 0, MR = -1;
    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r, ind = q[i].ind;
        // add
        while (ML > l) upd(FT[--ML], 1);
        while (MR < r) upd(FT[++MR], 1);
        // remove
        while (ML < l) upd(FT[ML++], -1);
        while (MR > r) upd(FT[MR--], -1);
        ans[ind] = res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, s, c;
    cin >> n >> m >> s;
    for (int i = 0; i < n-1; i++) cin >> a >> b, g[a].pb(b), g[b].pb(a);
    dfs(s, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (mp.find(c) == mp.end()) mp[c] = mp.size();
        col[i] = mp[c];
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        q[i] = Query(in[x], out[x], i);
    }
    sort(q, q+m);
    moalgo(m);
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
}
