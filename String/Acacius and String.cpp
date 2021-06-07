#include <bits/stdc++.h>
#include <string.h>
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

// https://codeforces.com/contest/1379/problem/A

string p = "abacaba";
int getCnt(string s) {
    int cnt = 0, n = s.size();
    for (int i = 0; i <= n-7; i++) {
        string temp = s.substr(i, 7);
        if (temp.compare(p) == 0) cnt++;
    }
    return cnt;
}

bool canConvert(string s) {
    bool ok = true;
    for (int i = 0; i < s.size() && ok; i++) {
        if (s[i] != '?') ok = s[i] == p[i];
    }
    return ok;
}

void mkString(string &t) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '?') t[i] = 'z';
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i <= n-7; i++) {
        if (canConvert(s.substr(i, 7))) {
            string t = s;
            for (int j = i; j < i+7; j++) t[j] = p[j-i];
            mkString(t);
            if (getCnt(t) == 1) {
                cout << "YES\n";
                cout << t << endl;
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

