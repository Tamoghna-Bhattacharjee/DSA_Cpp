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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
}