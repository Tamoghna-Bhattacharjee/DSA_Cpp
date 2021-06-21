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
const int N = 1e6;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/problemset/problem/459/D

// the problem is same as finding the number of element greater than k in a given range

int n, a[N+1], pref[N+1], suf[N+1];
vi st[4*N+4];

vi merge(vi &t1, vi &t2) {
    vi temp;
    int n = t1.size(), m = t2.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (t1[i] < t2[j]) temp.pb(t1[i++]);
        else temp.pb(t2[j++]);
    }
    while(i < n) temp.pb(t1[i++]);
    while(j < m) temp.pb(t2[j++]);
    return temp;
}

int query(int si, int ss, int se, int qs, int qe, int k) {
    if ((qs > se) || (qe < ss) || (ss > se)) return 0;
    if ((ss >= qs) && (se <= qe)) {
        return st[si].size() - (upper_bound(st[si].begin(), st[si].end(), k) - st[si].begin());
    }
    int mid = (ss+se) / 2;
    int l = query(2*si, ss, mid, qs, qe, k);
    int r = query(2*si + 1, mid+1, se, qs, qe, k);
    return l+r;
}

void buildTree(int si, int ss, int se) {
    if (ss > se) return;
    if (ss == se) {
        st[si].pb(pref[ss]);
        return;
    }
    int mid = (ss + se) / 2;
    buildTree(2*si, ss, mid);
    buildTree(2*si + 1, mid+1, se);
    st[si] = merge(st[2*si], st[2*si+1]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
        pref[i] = mp[a[i]];
    }
    mp.clear();
    buildTree(1,1,n);
    lli ans = 0;

    for (int i = n; i >= 2; i--) {
        mp[a[i]]++;
        suf[i] = mp[a[i]];
        ans += query(1,1,n,1,i-1,suf[i]);
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