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
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};
const double PI = acos(-1);


// https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/

lli getDist(vi &a, vi &b) {
    return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}

void mkArray(set<vi> &s, int idx, int val, vector<vi> &a, bool rev) {
    set<vi> tmp;
    for (auto &i: s) {
        if (i[idx] == val) tmp.insert(i);
    }
    if (rev) {
        for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
            s.erase(*it), a.push_back(*it);
        }
    } else {
        for (auto &i: tmp) s.erase(i), a.push_back(i);
    }
}

bool check(vector<vi> &a, lli d, int k) {
    int n = a.size();
    queue<int> q;
    vector<int> nxt(n, -1);
    for (int i = 0; i < n; i++) {
        while (!q.empty() && getDist(a[i], a[q.front()]) >= d) {
            nxt[q.front()] = i;
            q.pop();
        }
        q.push(i);
    }
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int pos = i;
        for (int j = 1; j <= k-1; j++) {
            if (nxt[pos] == -1) break;
            if (getDist(a[nxt[pos]], a[i]) >= d) {
                cnt++;
                pos = nxt[pos];
            } else break;
        }
        if (cnt >= k) return true;
    }
    return false;
}

void solve() {
    int n, side, k; cin >> n >> side >> k;
    vector<vi> points(n, vi(2));
    for (auto &i: points) cin >> i[0] >> i[1];

    vector<vi> a;
    set<vi> s(all(points));
    mkArray(s, 1, 0, a, false);
    mkArray(s, 0, side, a, false);
    mkArray(s, 1, side, a, true);
    mkArray(s, 0, 0, a, true);

    int ans = 0;
    lli L = 0, R = side;
    while (L <= R) {
        lli mid = (L + R) >> 1;
        if (check(a, mid, k)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }

    cout << ans << endl;
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