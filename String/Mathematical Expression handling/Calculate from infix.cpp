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

// https://leetcode.com/problems/basic-calculator/submissions/

int getPriority(char ch) {
    if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

int applyOperation(int x, int y, char op) {
    if (op == '+') return x+y;
    else if (op == '-') return x - y;
    else if (op == '*') return x*y;
    else return x/y;
}

int calculate(string s) {
    int n = s.size();
    stack<int> vals; vals.push(0);
    stack<char> op;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') continue;
        if (s[i] >= '0' && s[i] <= '9') {
            int x = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            vals.push(x);
            i--;
        } else if (s[i] == '(') op.push(s[i]);
        else if (s[i] == ')') {
            while (op.top() != '(') {
                int v2 = vals.top(); vals.pop();
                int v1 = vals.top(); vals.pop();
                char bop = op.top(); op.pop();
                vals.push(applyOperation(v1,v2,bop));
            }
            op.pop();
        } else {
            while (!op.empty() && getPriority(op.top()) >= getPriority(s[i])) {
                int v2 = vals.top(); vals.pop();
                int v1 = vals.top(); vals.pop();
                char bop = op.top(); op.pop();
                vals.push(applyOperation(v1,v2,bop));
            }
            op.push(s[i]);
        }
    }
    while (!op.empty()) {
        int v2 = vals.top(); vals.pop();
        int v1 = vals.top(); vals.pop();
        char bop = op.top(); op.pop();
        vals.push(applyOperation(v1,v2,bop));
    }
    return vals.top();
}

void solve() {
    string s; cin >> s;
    cout << calculate(s) << endl;
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