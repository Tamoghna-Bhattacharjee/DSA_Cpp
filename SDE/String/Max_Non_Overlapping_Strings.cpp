#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/

vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> L(26, INT_MAX), R(26, -1);
    for (int i = 0; i < n; i++) {
        L[s[i] - 'a'] = min(L[s[i] - 'a'], i);
        R[s[i]-'a'] = i;
    }
    vector<bool> visit(26, false);
    for (char i: s) {
        if (visit[i-'a']) continue;
        visit[i-'a'] = true;
        for (int j = L[i-'a'] + 1; j <= R[i-'a']; j++) {
            if (L[s[j]-'a'] < L[i-'a']) R[i-'a'] = -1;
            else R[i-'a'] = max(R[i-'a'], R[s[j]-'a']);
        }
    }
    vector<pair<int, int>> v;
    for (char i: s) {
        if (R[i-'a'] == -1) continue;
        if (!v.empty() && L[i-'a'] <= v.back().first) continue;
        if (v.empty()) v.push_back({L[i-'a'], R[i-'a']});
        else if (L[i-'a'] > v.back().second) v.push_back({L[i-'a'], R[i-'a']});
        else v.back() = {L[i-'a'], R[i-'a']};
    }
    vector<string> res;
    for (auto i: v) res.push_back(s.substr(i.first, i.second-i.first+1));
    return res;
}

void solve() {
    string s; cin >> s;
    debug(maxNumOfSubstrings(s));
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