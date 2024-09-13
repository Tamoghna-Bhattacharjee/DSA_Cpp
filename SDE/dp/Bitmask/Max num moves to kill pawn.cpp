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
const int di[] = {-2,-1,1,2,2,1,-1,-2}, dj[] = {1,2,2,1,-1,-2,-2,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);

// https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/

int dist[50][50][50][50];
int n;

bool isValid(int i, int j) {
    return i >= 0 && i <= 49 && j >= 0 && j <= 49;
}

void bfs(int si, int sj) {
    dist[si][sj][si][sj] = 0;
    queue<pair<int, int>> q; q.push({si, sj});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int i = cur.first, j = cur.second;
        for (int k = 0; k < 8; k++) {
            int ni = i+di[k], nj = j+dj[k];
            if (isValid(ni, nj) && dist[si][sj][i][j] + 1 < dist[si][sj][ni][nj]) {
                q.push({ni, nj});
                dist[si][sj][ni][nj] = dist[si][sj][i][j] + 1;
            }
        }
    }
}

void pre() {
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            for (int k = 0; k < 50; k++)
                for (int l = 0; l < 50; l++) dist[i][j][k][l] = INT_MAX;

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) bfs(i,j);
    }
}

int f(int idx, int mask, int player, vector<vector<vi>> &dp, vector<vi> &pos) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[idx][mask][player] != -1) return dp[idx][mask][player];

    int i = pos[idx][0], j = pos[idx][1];
    int ans = player == 0? 0: 10000;
    
    for (int k = 0; k < n; k++) {
        if ((mask >> k) & 1) continue;
        int ni = pos[k][0], nj = pos[k][1];
        if (player == 0) 
            ans = max(ans, dist[i][j][ni][nj] + f(k, mask | (1 << k), 1^player, dp, pos));
        else
            ans = min(ans, dist[i][j][ni][nj] + f(k, mask | (1 << k), 1^player, dp, pos));
    }
    return dp[idx][mask][player] = ans;
}

void solve() {
    int kx, ky; cin >> n >> kx >> ky;
    vector<vi> pos(n, vi(2));
    for (auto &i: pos) cin >> i[0] >> i[1];
    pos.pb({kx, ky});
    vector<vector<vi>> dp(n + 5, vector<vi>(1 << n, vi(2, -1)));
    cout << f(n, 0, 0, dp, pos) << endl;
}
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t; pre();
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}