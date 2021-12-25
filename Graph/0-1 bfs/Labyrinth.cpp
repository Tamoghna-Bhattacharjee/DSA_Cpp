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

// https://codeforces.com/contest/1063/problem/B

int n, m, r, c, x, y;
vector<string> s;

bool isValid(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m && s[i][j] == '.';
}

void solve() {
    cin >> n >> m >> r >> c >> x >> y;
    s = vector<string> (n+1);
    vector<vpii> dist(n+1, vpii(m+1, {INT_MAX,INT_MAX}));
    vector<vector<bool>> visit(n+1, vector<bool>(m+1, false));
    for (int i = 1; i <= n; i++) {
        cin >> s[i]; s[i] = "#" + s[i];
    }
    deque<pair<int, vi>> pq;
    pq.push_front({0, {0, r, c}});
    dist[r][c] = {0,0};
    int res = 0;
    while (!pq.empty()) {
        auto cur = pq.front(); pq.pop_front();
        int Ld = -cur.first; vi v = cur.second;
        int Rd = v[0], i = v[1], j = v[2];
        if (visit[i][j]) continue;
        
        visit[i][j] = true;
        if (Ld <= x && Rd <= y) res++;
        for (int k = 0; k < 4; k++) {
            int newI = i + di[k];
            int newJ = j + dj[k];
            if (isValid(newI, newJ)) {
                int newLd = Ld, newRd = Rd;
                if (dj[k] == -1) newLd++;
                if (dj[k] == 1) newRd++;
                
                if (newLd < dist[newI][newJ].first) {
                    dist[newI][newJ] = {newLd, newRd};
                    if (dj[k] == -1) pq.push_back({-newLd, {newRd, newI, newJ}});
                    else pq.push_front({-newLd, {newRd, newI, newJ}});
                }
            }
        }
    }
    
    
    cout << res << endl;
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}