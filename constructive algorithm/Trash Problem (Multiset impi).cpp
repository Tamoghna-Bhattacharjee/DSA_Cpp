#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back   
const lli INF = 1e18-1, MOD = 1000000007;
const int N = 1e5;

// https://codeforces.com/contest/1418/problem/D

set<int> p;
multiset<int, greater<int>> gaps;

void add(int x) {
    p.insert(x);
    auto it = p.find(x);
    if (next(it) != p.end()) gaps.insert(*next(it) - x);
    if (it != p.begin()) {
        gaps.insert(x - *prev(it));
        if (next(it) != p.end()) 
            gaps.erase(gaps.find(*next(it) - *prev(it)));
    }
}

void del(int x) {
    auto it = p.find(x);
    if (next(it) != p.end()) gaps.erase(gaps.find(*next(it) - x));
    if (it != p.begin()) {
        gaps.erase(gaps.find(x - *prev(it)));
        if (next(it) != p.end())
            gaps.insert(*next(it) - *prev(it));
                }
    p.erase(x);
}

void solve(){
    int n, q, x, ty; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> x, add(x);
    
    while (q--) {
        if ((int) p.size() <= 2) cout << 0 << endl;
        else cout << *p.rbegin() - *p.begin() - *gaps.begin() << endl;
        cin >> ty >> x;
        if (ty == 0) del(x);
        else add(x);
    }
    if ((int) p.size() <= 2) cout << 0 << endl;
    else cout << *p.rbegin() - *p.begin() - *gaps.begin() << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;  //cin >> t;
    while (t--) solve();
}