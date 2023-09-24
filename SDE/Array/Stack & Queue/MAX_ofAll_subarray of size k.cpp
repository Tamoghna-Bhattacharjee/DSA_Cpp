#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define ll long long
#define vi vector<int>
#define vlli vector<lli>
#define si set<int>
#define vpii vector<pair<int, int>>
#define vsi vector<set<int>>
#define pb push_back 
template<typename T> void debug(T _a) {cout << _a << " ";}
template<typename T1, typename T2> void debug(pair<T1, T2> _p) {cout<<"{"<<_p.first<<": "<<_p.second<<"}"<< endl;}
template<typename T> void debug(vector<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T> void debug(set<T> _aa) {for (auto i: _aa) debug(i); cout << endl;}
template<typename T1, typename T2> void debug(map<T1, T2> _mm) {for (auto i: _mm) debug(i);}

const lli INF = 1e18, MOD = 1e9 + 7;
const int N = 1e5; 
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string YN[] = {"NO", "YES"};

// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

void solve() {
    /*vi arr = {12, 1, 78, 90, 57, 89, 56};
    int k = 3;*/

    int n, k; cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vi res;
    deque<int> dq;
    int i = 0;
    while (i < k) {
        if (!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
        else dq.push_back(i++);
    }
    while (i < n) {   
        res.pb(arr[dq.front()]);
        while (!dq.empty() && dq.front() <= i-k) dq.pop_front(); // left element outside window
        while (!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
        dq.push_back(i++);   
    }
    res.pb(arr[dq.back()]);
    debug(res);
}   

int main() {
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << fixed << setprecision(9);
    int t = 1; //cin >> t;
    while (t--) solve();
}