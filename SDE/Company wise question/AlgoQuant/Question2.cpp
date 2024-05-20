#include <bits/stdc++.h>
#include <fstream>
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


// structure to store the data from file
struct Stock {
    vector<string> data;
    int id;
    int parentId;
    vector<Stock*> child;
};

// roots will only contain the parent nodes
map<int, Stock*> roots;

// taking input from file
void takeInput(string fileName, vector<Stock*> &stocks) {
    fstream fin;
    fin.open(fileName, ios::in);
    string inp;
    while (getline(fin, inp)) {
        vector<string> data(9);
        stringstream s(inp);
        for (int i = 0; i < 9; i++) {
            getline(s, data[i], ',');
        }
        debug(data);
        Stock *stock = new Stock();
        stock->parentId = atoi(data.back().c_str()); data.pop_back();
        stock->id = atoi(data.back().c_str()); data.pop_back();
        stock->data = data;
        stocks.emplace_back(stock);
    }
    fin.close();
}


// knapsac to decide the min number of parent node needed in one file to have all files having entries greater than x
set<int> getOneDiv(vector<pair<int, int>> &par, int x) {
    int n = par.size()-1;
    vector<vector<int>> dp(n+1, vector<int>(x+1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= x; sum++) {
            dp[i][sum] = dp[i-1][sum];         // if we don't take the ith element
            if (sum - par[i].first >= 0) 
                dp[i][sum] = min(dp[i][sum], 1 + dp[i-1][sum-par[i].first]);
        }
    }
    set<int> res;
    int i = n, sum = x;
    while (i > 0 && sum > 0) {
        if (dp[i][sum] == 1 + dp[i-1][sum-par[i].first])
            res.insert(par[i].second), sum = sum - par[i].first;
        i--;
    }
    return res;
}

// output the data
void printData(string fileName, set<int> ids) {
    fstream fout;
    fout.open(fileName, ios::out);
    for (int i: ids) {
        for (auto &s: roots[i]->data) fout << s << ",";
        fout << roots[i]->id << "," << roots[i]->parentId << endl;

        for (Stock* stock: roots[i]->child) {
            for (auto &s: stock->data) fout << s << ",";
            fout << stock->id << "," << stock->parentId << endl;
        }
    }
    fout.close();
}

void solve() {
    string fileName; cin >> fileName;
    int x; cin >> x;
    vector<Stock*> stocks;
    takeInput(fileName, stocks);

    // Contructing the grah
    // > adding parent nodes to root
    for (int i = 0; i < stocks.size(); i++) {
        if (stocks[i]->data[0] == "T") {
            roots[stocks[i]->id] = stocks[i];
        }
    }
    // adding child node to their parents
    for (int i = 0; i < stocks.size(); i++) {
        if (stocks[i]->data[0] == "P") {
            roots[stocks[i]->parentId]->child.push_back(stocks[i]);
        }
    }

    vector<pair<int, int>> par;
    par.push_back({0,0});
    // par is a vector (1 based indexing) which contain total no of rows for each root node
    // par = pair<no of rows needed per root node, root node id>
    for (auto &i: roots) {
        par.push_back({i.second->child.size() + 1, i.first});
    }
    // Spliting the large file into 2
    set<int> id1 = getOneDiv(par, x);
    set<int> id2;
    for (auto &i: roots) {
        if (id1.find(i.first) == id1.end()) id2.insert(i.first);
    }
    printData("outdata1.txt", id1);
    printData("outdata2.txt", id2);
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