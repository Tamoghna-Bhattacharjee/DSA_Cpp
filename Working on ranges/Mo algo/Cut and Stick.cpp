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
const int N = 3e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://codeforces.com/contest/1514/problem/D

const int SQN = sqrt(N);

struct query{
	int l, r;
	int idx;
	int block;
	query(){}
	query(int _l, int _r, int _id){
		l = _l;
		r = _r;
		block = _l/SQN;
		idx = _id;
	}
	bool operator < (const query &b) const{
		if(block != b.block)
			return block < b.block;
		return r < b.r;
	}

}queries[N+5];

int a[N+5], ans[N+5], f[N+5], n, q, coef[N+5];
int mx = 0;

void add(int i) {
    int val = a[i];
    coef[f[val]]--;
    f[val]++;
    coef[f[val]]++;
    mx = max(mx, f[val]);
}

void remove(int i) {
    int val = a[i];
    coef[f[val]]--;
    f[val]--;
    coef[f[val]]++;
    while (coef[mx] == 0) mx--;
}

void moalgo() {
    int ML = 0, MR = -1;
    for(int i = 0;i < q; i++){
		int l = queries[i].l, r = queries[i].r, idx = queries[i].idx;
		while(MR < r) MR++, add(MR);
		while(ML > l) ML--, add(ML);
		while(MR > r) remove(MR), MR--;
		while(ML < l) remove(ML), ML++;
        
        int len = r-l+1;
        if (mx <= (len+1)/2) ans[idx] = 1;
        else ans[idx] = 2*mx - len;        
	}
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; --l; --r;
        queries[i] = query(l,r,i);
    }
    sort(queries, queries + q);
    moalgo();
    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}   

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}