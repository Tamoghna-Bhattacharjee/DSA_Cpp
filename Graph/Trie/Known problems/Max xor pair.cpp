#include <bits/stdc++.h>
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
template<typename T> void debug(multiset<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto h: _aa) debug(h); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto h: _mm) debug(h);}

const lli INF = 1e18, MOD = 1e9+7;
const int N = 5e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};   

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

vector<vi> trie;
int nxt;
void insert(int n) {
    int cur = 0;
    for (int i = 31; i >= 0; i--) {
        bool v = (n & (1 << i)) != 0;
        if (trie[cur][v] == 0) {
            trie[cur][v] = ++nxt;
            trie.pb({0,0}); // inittializing nxt node
        }
        cur = trie[cur][v];
    }
}

int getMax(int n) {
    int cur = 0, x = 0;
    for (int i = 31; i >= 0; i--) {
        bool v = (n & (1 << i)) != 0;
        if (trie[cur][1^v] != 0) {
            x += (1 << i);
            cur = trie[cur][1^v];
        } else if (trie[cur][v] != 0) cur = trie[cur][v];
        else break;
    }
    return x;
}

void solve() {
    int n; cin >> n;
    int a[n]; for (int &i: a) cin >> i;
    trie = vector<vi>(1, vi(2)); // initializing root node
    nxt = 0;
    for (int i: a) insert(i);
    int mx = 0;
    for (int i: a) mx = max(mx, getMax(i));
    cout << mx << endl;
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