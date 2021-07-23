#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{";debug(_p.first);cout<<": ";debug(_p.second);cout<<"}\n";}
template<typename T> void debug(vector<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 998244353;
const int N = 1e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1#

// note that n elements are distinct
// idea -> compress the number such that the {min_num: 0, max_num: n-1}
// use the array as graph, and find the number of connected component(cc)
// if a cc is of size x, it will need x-1 swaps to get in the actual position corresponds to their index
// ans = Σ(cycle_size – 1) = n - (no of cc);

vi a, visit;

void dfs(int u) {
    visit[u] = 1;
    if (visit[a[u]] == 0)
        dfs(a[u]);
}

void solve () {
    int n; cin >> n;
    vi nums(n); for (int &i: nums) cin >> i;
    // number compression (0 indexed)
    set<int> s(nums.begin(), nums.end());
    map<int, int> mp;
    while (!s.empty()) {
        int x = mp.size();
        mp[*s.begin()] = x;
        s.erase(s.begin());
    }

    a = vi(n);
    visit = vi(n);
    for (int i = 0; i < n; i++) {
        a[i] = mp[nums[i]];
    }
    //debug(a);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visit[i] == 0) {
            dfs(i);
            cnt++;
        }
    }
    cout << n - cnt << endl;
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