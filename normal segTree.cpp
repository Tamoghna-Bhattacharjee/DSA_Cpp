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

const lli INF = 1e18, MOD = 998244353;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

lli segTree[4*N+4], lazyProp[4*N+4], diff_arr[N+1][N+1];

void rupd(int si, int ss, int se, int us, int ue, lli diff) {
    if (us > ue) return;
    if (lazyProp[si] != 0) {
        segTree[si] += (se - ss + 1) * lazyProp[si];
        if (ss != se) {
            lazyProp[2*si + 1] += lazyProp[si];
            lazyProp[2*si] += lazyProp[si];
        }
        lazyProp[si] = 0;
    }
    if (us > se || ue < ss || ss > se) return;
    if (ss >= us && se <= ue) {
        segTree[si] += (se - ss + 1) * diff;
        if (ss != se) {
            lazyProp[2*si + 1] += diff;
            lazyProp[2*si] += diff;
        }
        return;
    }
    int mid = (ss + se) / 2;
    rupd(2*si, ss, mid, us, ue, diff);
    rupd(2*si+1, mid+1, se, us, ue, diff);
    segTree[si] = segTree[2*si] + segTree[2*si + 1];
}   

lli qry(int si, int ss, int se, int qs, int qe) {
    if (lazyProp[si] != 0) {
        segTree[si] += (se - ss + 1) * lazyProp[si];
        if (ss != se) {
            lazyProp[2*si + 1] += lazyProp[si];
            lazyProp[2*si] += lazyProp[si];
        }
        lazyProp[si] = 0;
    }
    if (qs > se || qe < ss || ss > se) return 0;
    if (ss >= qs && se <= qe) return segTree[si];
    int mid = (ss + se)/2;
    lli l = qry(2*si, ss, mid, qs, qe);
    lli r = qry(2*si+1, mid+1, se, qs, qe);
    return l+r;
}

// WITHOUT LAZY PROGPAGATION
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

struct segTree {
    lli size;
    vector<node> st;
    node identity;

    void init(int x) {
        size = x;
        st.resize(4*size+4);
        identity = node(-INF); // change
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

    void rupd(int si, int ss, int se, int us, int ue, lli diff) {
        if (us > se || ue < ss || ss > se) return;
        if (ss >= us && se <= ue) { 
            // change
            st[si].mx += (se - ss + 1) * diff;
            return;
        }
        int mid = (ss + se) / 2;
        rupd(2*si, ss, mid, us, ue, diff);
        rupd(2*si + 1, mid + 1, se, us, ue, diff);
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

    // lli ptqry(int si, int ss, int se, int qs, int qe, lli x) {
    //     if (qs > se || qe < ss || ss > se) return -1;
    //     if (st[si].mx < x) return -1;
    //     if (ss == se) return ss;
    //     int mid = (ss + se) / 2;
    //     lli l = ptqry(2*si, ss, mid, qs, qe, x);
    //     if (l != -1) return l;
    //     lli r = ptqry(2*si + 1, mid+1,se, qs, qe, x);
    //     if (r != -1) return r;
    //     return -1;
    // }

    // driver code:
    void build (vlli &a) {
        // a must be 1-indexed
        build(1, 1, size, a);
    }

    void set(int ui, lli x) {
        set(1,1,size,ui, x);
    }

    void rupd(int us, int ue, lli diff) {
        if (us > ue) return;
        rupd(1, 1, size, us, ue, diff);
    }

    node qry (int qs, int qe) {
        if (qs > qe) return identity;
        return qry (1, 1, size, qs, qe);
    }

    // lli ptqry(lli x, int qs, int qe) {
    //     return ptqry(1,1,size,qs,qe,x);
    // }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
}