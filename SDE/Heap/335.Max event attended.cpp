#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 4e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

void solve() {
    int n; cin >> n;
    vector<vi> e;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        e.pb({l,r});
    }
    sort(e.begin(), e.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0, day = -1;
    int i = 0;
    while (!pq.empty() || i < n) {
        if (pq.empty()) day = e[i][0];
        while (i < n && e[i][0] == day) pq.push(e[i++][1]);
        pq.pop();
        ans++; day++;
        while (!pq.empty() && pq.top() < day) pq.pop();
    }
    cout << ans << endl;
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