#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

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

// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
// This method can be used for small value of a[i]

struct node {
    vlli F, pref;
    lli inv = 0;
    node() {
        // change
        F = vlli(41);
        pref = vlli(41);
        inv = 0;
    }
    node(lli x) {
        // change
        F = vlli(41);
        pref = vlli(41);
        inv = 0;
        F[x]++;
        for (int i = 1; i <= 40; i++) pref[i] = F[i] + pref[i-1];
    }
    void merge(node &l, node &r) {
        // change
        for (int i = 1; i <= 40; i++) F[i] = l.F[i] + r.F[i];
        for (int i = 1; i <= 40; i++) pref[i] = F[i] + pref[i-1];
        inv = l.inv + r.inv;
        for (int i = 1; i <= 40; i++) inv += l.F[i] * r.pref[i-1]; 
    }
};

struct segTree {
    lli size;
    vector<node> st;
    node identity;

    void init(int x) {
        size = x;
        st.resize(4*size+4);
        identity = node(); // change
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

    void set(int si, int ss, int se, int ui, lli x) {
        if (ss == se) {
            // change
            st[si] = node(x);
            return;
        }
        int mid = (ss + se) / 2;
        if (ui <= mid) set(2*si, ss, mid, ui, x);
        else set(2*si + 1, mid + 1, se, ui, x);
        st[si].merge(st[2*si], st[2*si + 1]);
    }

    node qry (int si, int ss, int se, int qs, int qe) {
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

    void set(int ui, lli x) {
        set(1,1,size,ui, x);
    }
    node qry (int qs, int qe) {
        if (qs > qe) return identity;
        return qry (1, 1, size, qs, qe);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vlli a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    segTree st; st.init(n);
    st.build(a);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << st.qry(l,r).inv << "\n";
        } else {
            int ind, y; cin >> ind >> y;
            st.set(ind, y);
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
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}