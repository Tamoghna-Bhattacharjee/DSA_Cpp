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
const int N = 3e4;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

vi g1[N+1], g2[N+1];

void makePseudoGroup(vector<int> &a, int &m) {
    // Replace -1 with a proper group number that is not being used
    int n = a.size();
    for (int &i: a) {
        if (i == -1) i = m, m++;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vi group(n); for (auto &i: group) cin >> i; // -1 <= group[i] <= m - 1
    makePseudoGroup(group, m);


    vi in1(n), in2(m); // in1 -> cnt indeg of nodes, in2 -> cnt indeg of grps
    // taking input for before items
    for (int i = 0; i < n; i++) {
        int k; cin >> k; // size of before item
        in1[i] = k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            g1[x].pb(i);
            if (group[x] != group[i]) 
                g2[group[x]].push_back(group[i]), in2[group[i]]++;
        }
    }

    // topo sort on nodes
    queue<int> nq;
    vector<vector<int>> sGrps(m); // sorted within group
    int cntNodes = 0;
    for (int i = 0; i < n; i++) {
        if (in1[i] == 0) nq.push(i);
    }
    while (!nq.empty()) {
        int u = nq.front(); nq.pop();
        cntNodes++;
        sGrps[group[u]].push_back(u);
        for (int v: g1[u]) {
            in1[v]--;
            if (in1[v] == 0) nq.push(v);
        }
    }
    if (cntNodes != n) {cout << -1 << endl; return;} // Cycle detected

    // topo sort on grp numbers
    queue<int> gq;
    vector<int> grpOrder;
    int cntGrps = 0;
    for (int i = 0; i < m; i++) {
        if (in2[i] == 0) gq.push(i);
    }
    while (!gq.empty()) {
        int u = gq.front(); gq.pop();
        cntGrps++;
        grpOrder.push_back(u);
        for (int v: g2[u]) {
            in2[v]--;
            if (in2[v] == 0) gq.push(v);
        }
    }
    if (cntGrps != m) {cout << -1 << endl; return;} // Cycle detected

    vector<int> ans;
    for (int i: grpOrder) {
        for (int j: sGrps[i]) ans.push_back(j);
    }
    debug(ans);
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