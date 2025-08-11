#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define lli long long int 
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define vpii vector<pair<int, int>>
#define pb push_back
#define all(__x) __x.begin(),__x.end()

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
const double PI = acos(-1);

// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/

// Final cnt = (T[next char][prev car] ^ t) * Initial cnt

class Matrix {
private:
    vector<vlli> a;

public:
    Matrix(vector<vlli> &a): a(a) {}
    Matrix(int n, bool isIdentity = false) {
        a = vector<vlli>(n, vlli(n));
        if (isIdentity) {
            for (int i = 0; i < n; i++) a[i][i]++;
        }
    }

    Matrix& operator*=(const Matrix &o) {
        int n = a.size();
        int m = o.a[0].size();
        int p = o.a.size();

        vector<vlli> result(n, vlli(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lli val = 0;
                for (int k = 0; k < p; k++) {
                    val = (val + (a[i][k] * o.a[k][j]) % MOD) % MOD;
                }
                result[i][j] = val;
            }
        }

        a = std::move(result);
        return *this;
    }

    const vector<vlli>& get() const { return a; }
};

void solve() {
    string s; cin >> s;
    int t; cin >> t;
    vi nums(26); for (auto &i: nums) cin >> i;
    vector<vlli> cnt(26, vlli(1)), T(26, vlli(26));
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]-'a'][0]++;
    }
    for (int i = 0; i < 26; i++) {
        int nch = i;
        while (nums[i]) {
            nch++; nch %= 26;
            T[nch][i]++;
            nums[i]--;
        }
    }

    Matrix A(T), C(cnt), I(26, true);
    while (t) {
        if (t & 1) I *= A;
        A *= A;
        t >>= 1;
    }
    
    I *= C;
    auto res = I.get();
    lli ans = 0;
    for (int i = 0; i < 26; i++) {
        (ans += res[i][0]) %= MOD;
    }

    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1; cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        //cout << "Case #" << _i << ": ";
        solve();
    }
}