#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vii vector<int, int>
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back

// https://codeforces.com/contest/1380/problem/A

void solve() {
    int n; cin >> n;
    int p[n];
    map<int, int> index, G, S;
    for (int i = 0; i < n; i++) cin >> p[i], index[p[i]] = i+1;
    stack<int> st1, st2;
    int i = 0;
    while (i < n) {
        if (!st1.empty() && p[i] > st1.top()) G[st1.top()] = p[i], st1.pop();
        else st1.push(p[i++]);
    }
    i = 0;
    while (i < n) {
        if (!st2.empty() && p[i] < st2.top()) S[st2.top()] = p[i], st2.pop();
        else st2.push(p[i++]);
    }
    for (auto it: G) {
        if (S.find(it.second) != S.end()) {
            int pi = it.first, pj = it.second, pk = S[it.second];
            if (index[pi] < index[pj] && index[pj] < index[pk]) {
                cout << "YES\n";
                cout << index[pi] << " " << index[pj] << " " << index[pk] << endl;
                return;
            }
        }
    }
    cout << "NO\n";
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}

