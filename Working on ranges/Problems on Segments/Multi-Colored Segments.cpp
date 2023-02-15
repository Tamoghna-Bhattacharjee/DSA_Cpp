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
const double PI = acos(-1);

// https://codeforces.com/contest/1741/problem/F

struct node {
    lli mx;
    node() {
        // change
        mx = -INF;
    }
    node(lli x) {
        // change
        mx = x;
    }
    void merge(node &l, node &r) {
        // change
        mx = max(l.mx, r.mx);
    }
};

struct update {
    lli v;
    update() {
        // chnage
        v = INF;
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
        a.mx = v;
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
        if (qs > qe) return node(INF);
        return qry (1, 1, size, qs, qe);
    }
};

void solve() {
    lli n; cin >> n;
    vector<pair<pair<lli, lli>, lli>> a(n+1), range(n+1);
    multiset<lli> s;
    map<lli, vlli> col;
    map<lli, lli> actToRng;
    for (int i = 1; i <= n; i++) {
        lli l, r, c; cin >> l >> r >> c;
        a[i] = {{l, r}, c};
        range[i] = {{l, r}, i};
        col[c].pb(i);
        s.insert(l); s.insert(r);
    }
    sort(range.begin() + 1, range.end());
    segTree st; st.init(n);
    for (int i = 1; i <= n; i++) {
        st.rupd(i, i, range[i].first.second);
        actToRng[range[i].second] = i;
    }
    vlli ans(n+1, INF);

    for (auto c: col) {
        for (auto i: c.second) {
            s.erase(s.find(a[i].first.first));
            s.erase(s.find(a[i].first.second));
            st.rupd(actToRng[i], actToRng[i], 0);
        }

        // computing
        for (auto i: c.second) {
            lli L = a[i].first.first, R = a[i].first.second;
            auto it = s.lower_bound(L);
            if (it != s.begin()) ans[i] = min(ans[i], L - *prev(it));
            if (it != s.end() && *it <= R) ans[i] = 0;
            it = s.upper_bound(R);
            if (it != s.end()) ans[i] = min(ans[i], *it - R);

            lli l = 1, r = n, idx = 1;
            while (l <= r) {
                lli mid = (l + r) / 2;
                if (range[mid].first.first <= L) l = mid + 1, idx = mid;
                else r = mid - 1;
            }
            
            if (idx-1 > 0 && st.qry(1, idx-1).mx >= L) ans[i] = 0;
        }

        for (auto i: c.second) {
            s.insert(a[i].first.first);
            s.insert(a[i].first.second);
            st.rupd(actToRng[i], actToRng[i], range[actToRng[i]].first.second);
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
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