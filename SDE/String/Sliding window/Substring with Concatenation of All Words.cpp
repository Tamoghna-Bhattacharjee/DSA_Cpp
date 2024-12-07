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

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 2e5;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

vector<int> findSubstring(string s, vector<string>& words) {
    int L = 0, R = 0, cnt = 0;
    map<string, int> w;
    for (auto i: words) w[i]++;
    vector<int> res;
    
    int n = s.size(), m = words[0].size();
    
    for (int i = 0; i < m; i++) {
        int L = i, R = i;
        map<string, int> taken;
        int cnt = 0;
        while (R < n) {
            if (R + m - 1 >= n) break;
            string ss = s.substr(R, m);
            if (w.find(ss) == w.end()) {
                R += m; L = R;
                taken = map<string, int>();
                cnt = 0;
            } else {
                if (taken[ss] + 1 <= w[ss]) {
                    taken[ss]++, cnt++, R += m;
                    if (cnt == words.size()) res.push_back(L);
                } else {
                    ss = s.substr(L,m);
                    taken[ss]--; cnt--;
                    L += m;
                }
            }
        }
    }
    return res;
}

void solve() {
    string s; cin >> s;
    int m; cin >> m;
    vector<string> words(m); for (auto &i: words) cin >> i;
    debug(findSubstring(s, words));
}   
  
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}