#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 

void debug(int _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18-1, MOD = 1e9 + 7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

// https://codeforces.com/contest/1428/problem/E

lli value(lli len, lli p) {
    lli v1 = len/p;
    lli cnt2 = len % p;
    lli cnt1 = p - cnt2;
    lli v2 = v1 + 1;
    return cnt1 * v1 * v1 + cnt2 * v2 * v2;
}

struct node {
    lli len, p;
    node(lli _l, lli _p) {
        len = _l; p = _p;
    }
	bool operator <(const node &b) const {
		lli imp1 = value(len, p) - value(len, p + 1);
        lli imp2 = value(b.len, b.p) - value(b.len, b.p + 1);
        return imp1 < imp2;
	}
};


void solve () {
    int n, k; cin >> n >> k;
    priority_queue<node> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; 
        pq.push(node(x, 1));
    }
    for (int i = 0; i < k-n; i++) {
        node cur = pq.top(); pq.pop();
        cur.p++;
        pq.push(cur);
    }
    lli ans = 0;
    while (!pq.empty()) {
        node cur = pq.top(); pq.pop();
        ans += value(cur.len, cur.p);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}