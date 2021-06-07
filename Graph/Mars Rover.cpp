#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vii vector<int, int>
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

//https://codeforces.com/contest/1010/problem/D

const int maxN = 1000001;
bool change[maxN];
struct Node {
    string t;
    vi child;
    int v, ind;
    Node() {}
    Node (string s, int l, int r, int i) {
        t = s; 
        child.pb(l); child.pb(r); v = 0; ind = i;
    }
    Node (string s, int x, int i) {
        t = s;
        if (t.compare("IN") == 0) v = x;
        else child.pb(x);
        ind = i;
    }
} g[maxN];

// normal dfs for finding the actual ans
void dfs1(int u) {
    string s = g[u].t;
    if (s.compare("IN") == 0) return;
    for (int v: g[u].child) dfs1(v);
    int val;
    if (s.compare("AND") == 0) val = g[g[u].child[0]].v & g[g[u].child[1]].v;
    else if (s.compare("OR") == 0) val = g[g[u].child[0]].v | g[g[u].child[1]].v;
    else if (s.compare("XOR") == 0) val = g[g[u].child[0]].v ^ g[g[u].child[1]].v;
    else val = 1 - g[g[u].child[0]].v;
    g[u].v = val;
}

// if by changing the children the current vertex got changed i.e 1 -> 0 or vice versa
// note the child for which the current vertex gets changed and call a dfs to that child
void dfs2(int u) {
    string s = g[u].t;
    if (s.compare("IN") == 0) return;
    else if (s.compare("NOT") == 0) change[g[u].child[0]] = true, dfs2(g[u].child[0]);
    else if (s.compare("AND") == 0) {
        Node a = g[g[u].child[0]], b = g[g[u].child[1]];
        if (a.v == 1 && b.v == 1) {
            change[a.ind] = true, change[b.ind] = true;
            dfs2(a.ind); dfs2(b.ind);
        }
        else if (a.v == 0 && b.v == 0) change[a.ind] = false, change[b.ind] = false;
        else if (a.v == 0) change[a.ind] = true, dfs2(a.ind);
        else change[b.ind] = true, dfs2(b.ind);
    }
    else if (s.compare("OR") == 0) {
        Node a = g[g[u].child[0]], b = g[g[u].child[1]];
        if (a.v == 0 && b.v == 0) {
            change[a.ind] = true, change[b.ind] = true;
            dfs2(a.ind); dfs2(b.ind);
        }
        else if (a.v == 1 && b.v == 1) change[a.ind] = false, change[b.ind] = false;
        else if (a.v == 1) change[a.ind] = true, dfs2(a.ind);
        else change[b.ind] = true, dfs2(b.ind);
    }
    else {
        Node a = g[g[u].child[0]], b = g[g[u].child[1]];
        change[a.ind] = true; change[b.ind] = true;
        dfs2(a.ind); dfs2(b.ind);
    }
}

int main() {
    int n, a, b;
    string s;
    cin >> n;
    vi leaf_index;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s.compare("IN") == 0 || s.compare("NOT") == 0) cin >> a, g[i] = Node(s, a, i);
        else cin>>a>>b, g[i] = Node(s, a, b, i);
        if (s.compare("IN") == 0) leaf_index.pb(i);
    }
    dfs1(1);
    dfs2(1);
    int ans = g[1].v;
    for (int i: leaf_index) {
        cout << (change[i]? 1-ans: ans);
    }
}