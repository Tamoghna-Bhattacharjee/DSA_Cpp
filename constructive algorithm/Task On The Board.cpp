#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define MOD 1000000007
#define pb push_back    

// https://codeforces.com/contest/1367/problem/D

void solve() {
    string s; cin >> s;
    int m; cin >> m;
    int b[m];   
    char t[m]; 
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(s.begin(), s.end());
    stack<pair<char, int>> st;
    for (char i: s) {
        if (st.empty() || st.top().first != i) st.push({i, 1});
        else st.top().second++;
    }
    for (int i = 0; i < m; i++) {
        vi z;
        for (int j = 0; j < m; j++) {
            if (b[j] == 0) z.pb(j);
        }
        if (z.size() == 0) break;
        else {
            while (st.top().second < z.size()) st.pop();
            char ch = st.top().first; st.pop();
            for (int j: z) {
                b[j] = -1, t[j] = ch;
                for (int k = 0; k < m; k++) {
                    if (b[k] > 0) b[k] -= abs(k-j);
                }
            }
        }
    }
    for (char i: t) cout << i;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}