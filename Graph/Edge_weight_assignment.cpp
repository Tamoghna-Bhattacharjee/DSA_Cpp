//https://codeforces.com/contest/1338/problem/B
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define MOD 1000000007
#define pb push_back

int depth[100001];
vi g[100001];
set<int> leaves, p2l;
bool visit[100001];

void dfs(int u, int p) {
    visit[u] = true;
    depth[u] = depth[p] + 1;
    if (g[u].size() == 1) leaves.insert(u), p2l.insert(g[u][0]);
    for (int v: g[u]) {
        if (!visit[v]) 
            dfs(v, u);
    }     
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; i++) g[i].clear(), visit[i] = false, leaves.clear(), depth[i] = -1, p2l.clear();
    for (int i = 0; i < n-1; i++) 
        cin >> a >> b, g[a].pb(b), g[b].pb(a);
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            root = i; break;
        }
    }
    dfs(root, 0);
    //cout<<"OUTPUT" << leaves.size()<<p2l.size() << endl;
    int min = 0, max = 0;
    for (int i: leaves) {
        //cout << i << " " << depth[i] << endl;
        if (depth[i] % 2 == 1) {
            min = 3; break;
        }else min = 1;         
    }
    //cout << "===============" << endl;
    max = (n-1) - leaves.size() + p2l.size();
    cout << min << " " << max << endl;
    return 0;  
}