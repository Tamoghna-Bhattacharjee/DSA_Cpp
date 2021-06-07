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

// https://codeforces.com/contest/1370/problem/C

int getDivisor (int n) {
    while (n % 2 == 0) n /= 2;
    return n;
}

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    bool winner[] = {true, true};
    int cnt = 0;
    while (winner[0] && winner[1]) {
        if (n == 1) winner[cnt%2] = false;
        else if (n % 2 == 1) winner[1-cnt%2] = false;
        else {
            int x = getDivisor(n);
            if (x % 2 == 1 && x != 1) {
                if (n/x == 2) {
                    if (isPrime(x)) winner[cnt%2] = false;
                    else winner[1-cnt%2] = false;
                } else n /= x;
            }
            else n--;
        }
        cnt++;
    }
    if (winner[0]) cout << "Ashishgup\n";
    else cout << "FastestFinger\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t = 1; cin >> t;
    while (t--) solve();
}

