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
#define all(__x) __x.begin(),__x.end()

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


// https://leetcode.com/problems/separate-squares-ii/

const int START = +1, END = -1;
struct Event {
	int x1, x2, y, type;
};

vi X;

struct node {
    lli sum;
    lli cnt;
    node() {
        // change
        sum = 0;
        cnt = 0;
    }
    node(lli x) {
        // change
        sum = x;
        cnt = 0;
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
        v += other.v;
    }
    void apply(node &a, int ss, int se) {
        // change
        a.cnt += v;
        if (a.cnt > 0) a.sum = X[se+1] - X[ss];
        else a.sum = 0;
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
        // pushdown(si, ss, se);
        if (us > se || ue < ss || ss > se) return;
        if (ss >= us && se <= ue) {
            st[si].cnt += upd.v;
        } else {
            int mid = (ss + se) / 2;
            rupd(2*si, ss, mid, us, ue, upd);
            rupd(2*si + 1, mid + 1, se, us, ue, upd);
        }
        if (st[si].cnt > 0) st[si].sum = X[se+1] - X[ss];
        else {
            if (ss == se) st[si].sum = 0;
            else st[si].sum = st[2*si].sum + st[2*si+1].sum;
        }
    }

    node qry (int si, int ss, int se, int qs, int qe) {
        // pushdown(si, ss, se);
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

map<int, int> compressX(vector<vi> &sq) {
    X.clear();
    set<int> s;
    for (auto &i: sq) {
        int x1 = i[0], x2 = i[0] + i[2];
        s.insert(x1); s.insert(x2);
    }
    map<int, int> mp;
    X.pb(0);
    for (int i: s) {
        int idx = mp.size() + 1;
        mp[i] = idx;
        X.pb(i);
    }
    return mp;
}

void solve() {
    int n; cin >> n;
    vector<vi> sq(n, vi(3));
    for (auto &i: sq) {
        for (auto &j: i) cin >> j;
    }

    auto mp = compressX(sq);
    int m = mp.size();
    vector<Event> events;
    for (auto &i: sq) {
        int x1 = mp[i[0]], x2 = mp[i[0]+i[2]];
        int y1 = i[1], y2 = i[1] + i[2];
        events.pb({x1, x2, y1, START});
        events.pb({x1, x2, y2, END});
    }
    sort(all(events), [](auto &a, auto &b) {return a.y < b.y;});
    
    segTree st; st.init(m);
    int prev_y = events[0].y;
    double tot = 0;
    for (auto &e: events) {
        tot += (e.y - prev_y) * st.qry(1, m).sum;
        prev_y = e.y;
        st.rupd(e.x1, e.x2-1, e.type);
    }
    
    double curr_area = 0;
    prev_y = events[0].y;
    for (auto &e: events) {
        double nxt_area = curr_area + (e.y - prev_y) * st.qry(1, m).sum;
        if (nxt_area * 2 == tot) {
            cout << e.y << endl;
            return;
        } else if (nxt_area * 2 > tot) {
            cout << prev_y + ((tot/2) - curr_area) / st.qry(1, m).sum << endl;
            return;
        } else curr_area = nxt_area;
        prev_y = e.y;
        st.rupd(e.x1, e.x2-1, e.type);
    }

    cout << "error\n";
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