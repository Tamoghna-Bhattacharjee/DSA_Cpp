#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

// https://cses.fi/problemset/task/1192/

char G[1000][1000];
bool visit[1000][1000];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int N, M;

bool isValid(int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= M) return false;
    if (visit[i][j] || G[i][j] == '#') return false;
    return true;
}

void dfs(int x, int y) {
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) 
        if (isValid(x+dx[i], y+dy[i])) 
            dfs(x+dx[i], y+dy[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) cin >> G[i][j];
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (G[i][j] == '.' && !visit[i][j]) cnt++, dfs(i, j);
        }
    }
    cout << cnt << endl;
}
    