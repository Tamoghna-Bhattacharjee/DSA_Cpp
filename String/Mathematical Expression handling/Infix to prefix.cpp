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

// https://www.geeksforgeeks.org/convert-infix-prefix-notation/

int getPriority(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

string getInfix_to_prefix(string s) {
    int n = s.size();
    // 1. reverse the string and change the pairity of brackets;
    reverse(s.begin(), s.end()); 
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') s[i] = '(';
        else if (s[i] == '(') s[i] = ')';
    }
    // Almost postfix algo
    stack<char> st;
    string res;
    for (char i: s) {
        if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) res.pb(i);
        else if (i == '(') st.push(i);
        else if (i == ')') {
            while (st.top() != '(') res.pb(st.top()), st.pop();
            st.pop();
        } else {
            if (i == '^') {
                while (!st.empty() && getPriority(st.top()) >= getPriority(i))
                    res.pb(st.top()), st.pop();
            } else {
                while (!st.empty() && getPriority(st.top()) > getPriority(i))
                    res.pb(st.top()), st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) res.pb(st.top()), st.pop();
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string s; cin >> s;
    cout << getInfix_to_prefix(s) << endl;
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