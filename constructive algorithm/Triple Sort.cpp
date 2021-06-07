#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/MAY20B/problems/TRPLSRT
void solve() {
    int n, k, m = 0;
    cin >> n >> k;
    int arr[n], sortArray[n], ans[k][3];

    for (int i = 0; i < n; i++) cin >> arr[i], sortArray[i] = arr[i];
    sort(sortArray, sortArray+n);

    map<int, set<int>> rightIndex; // location of sorted elemenent in sortedArray
    set<int> wrongIndex;
    queue<pair<int, int>>interConn;

    for (int i = 0; i < n; i++) 
        if (arr[i] != sortArray[i]) rightIndex[sortArray[i]].insert(i), wrongIndex.insert(i);
    

    for (int i = 0; i < k && wrongIndex.size() != 0; i++) {
        int i1 = *wrongIndex.begin(), i2 = -1, i3 = -1;
        if (rightIndex[arr[i1]].size() == 0) break;
        else i2 = *rightIndex[arr[i1]].begin();
        if (rightIndex[arr[i2]].size() == 0) break;
        else i3 = *rightIndex[arr[i2]].begin();

        if (i3 == i1) {
            // treating interconnected separately
            interConn.push({i1, i2});
            wrongIndex.erase(i1), wrongIndex.erase(i2);
            rightIndex[arr[i1]].erase(i2); rightIndex[arr[i2]].erase(i1);
        }else {
            // cyclic rotation
            ans[m][0] = i1; ans[m][1] = i2; ans[m][2] = i3;
            int x = arr[i1], y = arr[i2], z = arr[i3];
            arr[i1] = z; arr[i2] = x; arr[i3] = y;

            for (int index: ans[m]) {
                if (arr[index] == sortArray[index]) rightIndex[sortArray[index]].erase(index), wrongIndex.erase(index);
            }
            m++;
        }
    }
    // odd no. of inerconnected pair can't be sorted by cyclic rotations
    if (interConn.size() % 2 == 1) {
        cout << -1 << endl; return;
    }

    while (!interConn.empty()) {
        /*
            any 2 inter connected pair i.e 4 element can be sorted in 2 steps
            b a d c => d b a c => a b c d 
        */
        pair<int, int> pair1 = interConn.front(); interConn.pop();
        pair<int, int> pair2 = interConn.front(); interConn.pop();
        int i1 = pair1.first, i2 = pair1.second, i3 = pair2.first, ind4 = pair2.second;

        ans[m][0] = i1; ans[m][1] = i2; ans[m][2] = i3; m++;
        int x = arr[i1], y = arr[i2], z = arr[i3];
        arr[i1] = z; arr[i2] = x; arr[i3] = y;

        ans[m][0] = i1; ans[m][1] = ind4; ans[m][2] = i3; m++;
        x = arr[i1]; y = arr[ind4]; z = arr[i3];
        arr[i1] = z; arr[ind4] = x; arr[i3] = y;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (arr[i] != sortArray[i]) {
            ok = false; break;
        }
    }
    if (ok) {
        cout << m << endl;
        for (int i = 0; i < m; i++) 
            cout << ans[i][0]+1 << " " << ans[i][1]+1 << " " << ans[i][2]+1 << endl;
    }else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}
