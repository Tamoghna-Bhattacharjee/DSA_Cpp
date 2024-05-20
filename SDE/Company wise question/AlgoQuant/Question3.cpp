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

// Assuming max number of operation => Enqueue + Dequeue <= 1e5

struct Element {
    int val;
    int version;
    Element *next;
    Element *prev;

    Element() {
        val = INT_MIN; version = -1;
        next = nullptr;
        prev = nullptr;
    }

    Element(int val, int version): val(val), version(version) {
        next = nullptr;
        prev = nullptr;
    }
};

class Queue {
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        version = 1;
    }

    void enqueue(int val) {
        Element* ele = new Element(val, version);
        version++;
        if (tail == nullptr) {
            head = ele;
            tail = ele;
        } else {
            tail->next = ele;
            ele->prev = tail;
            tail = ele;
        }
    }

    int deque() {
        assert(head != nullptr && tail != nullptr);
        Element* ptr = head;
        version++;
        int res = ptr->val;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
            ptr->next = nullptr;
        }
        delete ptr;
        return res;
    }

    void print(int ver) {
        if (head == nullptr) return;
        cout << "==== Print Ele with version = " << ver << " ====" << endl;
        Element* cur = head;
        while (cur) {
            if (cur->version == ver) {
                cout << cur->val << " ";
                break;
            }
            cur = cur->next;
        }
        cout << endl;
        cout << "==================\n";
    }

private:
    Element* head;
    Element* tail;
    int version;
};

void solve() {
    int n; cin >> n; // total number of inputs
    Queue q;
    while (n--) {
        string type; cin >> type;
        if (type == "enqueue") {
            int val; cin >> val;
            q.enqueue(val);
        } else if (type == "deque") {
            cout << q.deque() << endl;
        } else {
            int ver; cin >> ver;
            q.print(ver);
        }
    }
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