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
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"}; 

// Heap representation in an array (1 based index)
// if Node at index i
// left child = 2*i, right child = 2*i+1;
// parent = i/2;
// filling would be done level by level and it should be a full binary tree
// MAX Heap -> every node has value > value of its descendents 
// MIN Heap -> every node has value < value of its descendents

vi a;

void insertNode(int k) {
    int ind = a.size();
    a.pb(k); 
    while (1) {
        int par = ind/2;
        if (par == 0) break;
        if (k < a[par]) {
            swap(a[ind], a[par]);
            ind = par;
        } else break;
    }
}

void deleteNode() {
    if (a.size() == 1) {
        a.pop_back(); return; 
    }
    a[1] = a.back(); a.pop_back();
    int ind = 1;
    while (ind < a.size()) {
        int lft_ind = 2*ind, rgt_ind = 2*ind+1;
        if (lft_ind >= a.size() && rgt_ind >= a.size()) break;
        else if (lft_ind >= a.size()) {
            if (a[ind] > a[rgt_ind]) swap(a[ind], a[rgt_ind]), ind = rgt_ind;
            else break;
        } else if (rgt_ind >= a.size()) {
            if (a[ind] > a[lft_ind]) swap(a[ind], a[lft_ind]), ind = lft_ind;
            else break;
        } else {
            if (a[lft_ind] <= a[rgt_ind] && a[lft_ind] <= a[ind]) 
                swap(a[ind], a[lft_ind]), ind = lft_ind;
            else if (a[rgt_ind] <= a[lft_ind] && a[rgt_ind] <= a[ind])
                swap(a[ind], a[rgt_ind]), ind = rgt_ind;
            else break;
        }
    }
}

int getTop() {
    if (a.size() > 1) return a[1];
    else return INT_MIN;
}

void solve() {
    a = vi(1);
    int q; cin >> q;
    while (q--) {
        char ch; cin >> ch;
        if (ch == 'i') {
            int k; cin >> k; insertNode(k);
        } else deleteNode();
        cout << "top = " << getTop() << endl;
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