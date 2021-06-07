#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1520/problem/F2

int lazy[4*N+4], st[4*N+4], n;
set<int> s;

void doLazy(int si, int ss, int se) {
    if (lazy[si] != 0) {
        st[si] += lazy[si];
        if (ss != se) {
            lazy[2*si] += lazy[si];
            lazy[2*si+1] += lazy[si];
        }
        lazy[si] = 0;
    } 
}

int qry(int si, int ss, int se, int qi) {
    if (ss > se) return 0;
    doLazy(si, ss, se);
    if (ss == se) return st[si];
    int mid = (ss + se)/2;
    if (qi <= mid) return qry(2*si, ss, mid, qi);
    else return qry(2*si + 1, mid + 1, se, qi);
}

void upd(int si, int ss, int se, int ui, int val) {
    if (ss > se) return;
    doLazy(si, ss, se);
    if (ss == se) {
        st[si] = val;
        return;
    }
    int mid = (ss + se)/2;
    if (ui <= mid) upd(2*si, ss, mid, ui, val);
    else upd(2*si+1, mid+1, se, ui, val);
}
void add(int si, int ss, int se, int us, int ue) {
    if (ss > se) return;
    doLazy(si, ss, se);
    if (us > se || ue < ss) return;
    if (ss >= us && se <= ue) {
        lazy[si]++;
        doLazy(si, ss, se);
        return;
    }
    int mid = (ss + se)/2;
    add(2*si, ss, mid, us, ue);
    add(2*si+1, mid + 1, se, us, ue);
}

int get(int mid) {
    if (s.find(mid) == s.end()) {
        cout << "? 1 " << mid << endl; cout.flush();
        int sum; cin >> sum;
        s.insert(mid);
        upd(1,1,n,mid, sum);
    } 
    return qry(1, 1, n, mid);
}

int f(int k) {
    int L = 1, R = n;
    while (L <= R) {
        int mid = (L + R) / 2;
        int x = mid - get(mid);
        if (x >= k) R = mid - 1;
        else L = mid + 1;
    }
    return R + 1;
}

void solve() {
    int t; cin >> n >> t;
    while (t--) {
        int k; cin >> k;
        int p = f(k);
        cout << "! " << p << endl;
        add(1,1,n,p,n);
    }
}  

int main() {
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}