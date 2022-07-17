#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

struct Rank {
	int idx; 
	int abil; 
};
Rank rk[500'002];

bool abilComp(const Rank& rk1,const Rank& rk2){
	return rk1.abil < rk2.abil;
}
bool IdxComp(const Rank& rk1, const Rank& rk2) {
	return rk1.idx < rk2.idx;
}

int* tree;


int sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2+1, mid+1, end, left, right);
}

void update(int node,int start,int end, int idx) {
	if (start > idx || end < idx) {
		return;
	}

	tree[node]++;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx);
	update(node * 2+1, mid+1, end, idx);

}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int height = (int)ceil(log2(N));
	int TreeSize = 1 << (height + 1);
	tree = new int[TreeSize]();
	
	for (int i = 0; i < N; i++) {
		cin >> rk[i].abil;
		rk[i].idx = i;
	}

	sort(rk, rk + N, abilComp);
	for (int i = 0; i < N; i++) {
		rk[i].abil = i;
	}
	sort(rk, rk + N, IdxComp);

	for (int i = 0; i < N; i++) {
		int fr= sum(1, 0, N - 1, 0, rk[i].abil);
		cout << i - fr + 1 << "\n";
		update(1, 0, N - 1, rk[i].abil);
	}
	
	delete[] tree;
	return 0;
}