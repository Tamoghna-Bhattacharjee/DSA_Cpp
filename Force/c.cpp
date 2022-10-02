#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back 

template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(deque<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

// typedef tree<int, null_type, less<int>, 
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

struct node {
    lli sum;
    node() {
        // change
        sum = 0;
    }
    node(lli x) {
        // change
        sum = x;
    }
    void merge(node &l, node &r) {
        // change
        sum = l.sum + r.sum;
    }
};

struct update {
    lli v;
    update() {
        // chnage
        v = 0;
    }
    update(lli x) {
        // chnage
        v = x;
    }
    void combine(update &other) {
        // change
        v = other.v;
    }
    void apply(node &a, int ss, int se) {
        // change
        a.sum = v;
    }
    bool operator==(update &other) {
        // change
        return v == other.v;
    } 
};

struct segTree {
    lli size;
    vector<node> st;
    vector<update> lazy;
    node identity;
    update identity_update;

    void init(int x) {
        size = x;
        st.resize(4*size+4); // chnage
        lazy.resize(4*size+4);
        identity = node(); // change
        identity_update = update(); // change
    }

    void pushdown(int si, int ss, int se) {
        if (lazy[si] == identity_update) return;
        lazy[si].apply(st[si], ss, se);
        if (ss != se) {
            lazy[2*si].combine(lazy[si]);
            lazy[2*si+1].combine(lazy[si]);
        }
        lazy[si] = identity_update;
    }

    void build (int si, int ss, int se, vlli &a) {
        if (ss > se) return;
        if (ss == se) {
            st[si] = node(a[ss]); // change
            return;
        }
        int mid = (ss + se) / 2;
        build (2*si, ss, mid, a);
        build (2*si + 1, mid + 1, se, a);
        st[si].merge(st[2*si], st[2*si+1]);
    }

    void rupd(int si, int ss, int se, int us, int ue, update &upd) {
        pushdown(si, ss, se);
        if (us > se || ue < ss || ss > se) return;
        if (ss >= us && se <= ue) { 
            lazy[si].combine(upd);
            pushdown(si, ss, se);
            return;
        }
        int mid = (ss + se) / 2;
        rupd(2*si, ss, mid, us, ue, upd);
        rupd(2*si + 1, mid + 1, se, us, ue, upd);
        st[si].merge(st[2*si], st[2*si + 1]);
    }

    node qry (int si, int ss, int se, int qs, int qe) {
        pushdown(si, ss, se);
        if (qs > se || qe < ss || ss > se) return identity;
        if (ss >= qs && se <= qe) return st[si];
        int mid = (ss + se)/2;
        node l = qry(2*si, ss, mid, qs, qe);
        node r = qry(2*si+1, mid+1, se, qs, qe);
        node res; res.merge(l,r);
        return res;
    }

    // driver code:
    void build (vlli &a) {
        // a must be 1-indexed
        build(1, 1, size, a);
    }

    void rupd(int us, int ue, lli v) {
        if (us > ue) return;
        update upd(v);
        rupd(1, 1, size, us, ue, upd);
    }

    node qry (int qs, int qe) {
        if (qs > qe) return identity;
        return qry (1, 1, size, qs, qe);
    }
};

struct HLD {
    int n, root, tmr;
    vector<vi> g;
    vlli val;
    vi level, sz, tin, tout, head, par, heavy;
    segTree st;

    void init(int NN, vlli &v, int r = 1) {
        n = NN; root = r; tmr = 0;
        g = vector<vi>(n+1);
        val = v;
        st.init(n);
        level = vi(n+1); level[0] = -1;
        sz = vi(n+1);
        tin = vi(n+1); tout = vi(n+1);
        head = vi(n+1); par = vi(n+1); heavy = vi(n+1, -1);
        for (int i = 1; i <= n; i++) head[i] = i;
    }

    void addEdge(int a, int b) {
        g[a].pb(b); g[b].pb(a);
    }

    void dfs_hld(int u, int p) {
        sz[u] = 1; level[u] = level[p] + 1; 
        par[u] = p;
        int mx = 0; 
        for (int v: g[u]) {
            if (v != p) {
                dfs_hld(v, u);
                sz[u] += sz[v];
                if (sz[v] > mx) mx = sz[v], heavy[u] = v;
            }
        }
    }

    void decompose(int u, int p, int h) {
        tin[u] = ++tmr; head[u] = h;
        st.rupd(tmr, tmr, val[u]);
        if (heavy[u] != -1) decompose(heavy[u], u, h);
        for (int v: g[u]) {
            if (v != p && v != heavy[u]) decompose(v, u, v);
        }
        tout[u] = tmr;
    }

    void build() {
        dfs_hld(root, 0);
        decompose(root, 0, root);
    }

    void rupd(lli a, lli b, lli v) {
        while (head[a] != head[b]) {
            if (level[head[a]] > level[head[b]]) swap(a, b);
            st.rupd(tin[head[b]], tin[b], v);
            b = par[head[b]];
        }
        if (level[a] > level[b]) swap(a, b);
        st.rupd(tin[a], tin[b], v);
    }

    node qry(lli a, lli b) {
        node res;
        while (head[a] != head[b]) {
            if (level[head[a]] > level[head[b]]) swap(a, b);
            node x = st.qry(tin[head[b]], tin[b]);
            res.merge(res, x);
            b = par[head[b]];
        }
        if (level[a] > level[b]) swap(a, b);
        node x = st.qry(tin[a], tin[b]);
        res.merge(res, x);
        res.sum -= st.qry(tin[a], tin[a]).sum;
        return res;
    } 
};

vector<vpii> g;
vlli w, val, edgeToNode;

void dfs(int u, int p) {
    for (auto to: g[u]) {
        int v = to.first, ind = to.second;
        if (v != p) {
            dfs(v, u);
            edgeToNode[ind] = v;
            val[v] = w[ind];
        }
    }
}

void solve() {
    int n; cin >> n;
    g = vector<vpii>(n+1);
    w = vlli(n+1), val = vlli(n+1), edgeToNode = vlli(n+1);
    HLD hld; hld.init(n, val, 1);
    for (int i = 1; i <= n-1; i++) {
        int a, b; cin >> a >> b >> w[i];
        hld.addEdge(a, b);
        g[a].pb({b, i}); g[b].pb({a, i});
    }
    dfs(1, 0);
    hld.val = val;
    hld.build();
    while (true) {
        string s; cin >> s;
        if (s[0] == 'D') break;
        else if (s[0] == 'C') {
            int ind; cin >> ind; cin >> w[ind];
            hld.rupd(edgeToNode[ind], edgeToNode[ind], w[ind]);
        } else {
            int a, b; cin >> a >> b;
            cout << hld.qry(a, b).sum << endl;
        }
    }
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}