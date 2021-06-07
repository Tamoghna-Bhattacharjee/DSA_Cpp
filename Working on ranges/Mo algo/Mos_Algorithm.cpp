//https://www.spoj.com/problems/FREQ2/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
const int M = 1e5+5;
const int SQN = sqrt(N);

struct query{
	int l, r;
	int idx;
	int block;
	query(){}
	query(int _l, int _r, int _id){
		l = _l;
		r = _r;
		block = _l/SQN;
		idx = _id;
	}
	bool operator < (const query &b) const{
		if(block != b.block)
			return block < b.block;
		return r < b.r;
	}

};

query queries[M];
int ans[M], arr[N], freq[N], cof[N];;
int n, q;
int res = 0;

void add(int i) {
    int val = arr[i];
	cof[freq[val]]--;
	freq[val]++;
	cof[freq[val]]++;
	res = max(res, freq[val]);
}
void remove(int i) {
    int val = arr[i];
    cof[freq[val]]--;
	freq[val]--;
	cof[freq[val]]++;
	while(cof[res] == 0) res--;	
}
void moalgo() {
    int ML = 0, MR = -1;
    for(int i = 0;i < q; i++){
		int l = queries[i].l, r = queries[i].r, idx = queries[i].idx;
		while(MR < r) MR++, add(MR);
		while(ML > l) ML--, add(ML);
		while(MR > r) remove(MR), MR--;
		while(ML < l) remove(ML), ML++;
		ans[idx] = res;
	}
}
int main(){
	cin>>n>>q;
	for(int i = 0;i < n; i++) cin>> arr[i];
	for(int i = 0;i < q; i++){
		int l, r;
		cin>>l>>r;
		queries[i] = query(l, r, i);
	}
	sort(queries, queries+q);
	moalgo();
	for(int i = 0;i < q; i++) printf("%d\n", ans[i]);
	return 0;
}