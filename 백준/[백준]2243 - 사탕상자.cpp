#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define CANDYSIZE 1'000'000
using namespace std;

int N;
int A, B, C;

int counter[CANDYSIZE];
vector<int> tree;

int query(int node,int start,int end,int cnt) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (tree[node * 2] >= cnt)
		return query(node * 2, start, mid, cnt);
	return query(node * 2 + 1, mid + 1, end, cnt - tree[node * 2]);
}

void update(int node, int start, int end, int idx, int dif) {
	if (start > idx || idx > end) {
		return;
	}

	tree[node] += dif;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, dif);
	update(node * 2 + 1, mid + 1, end, idx, dif);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int height = (int)ceil(log2(CANDYSIZE));
	int treeSize = 1 << (height + 1);
	tree.resize(treeSize);

	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A == 1) {
			cin >> B;
			//사탕의 순위로 꺼내기-> 꺼낸 사탕의 맛의 번호 출력
			int pos = query(1, 1, CANDYSIZE, B);
			cout << pos << "\n";
			counter[pos]--;
			update(1, 1, CANDYSIZE, pos, -1);
		}
		else {
			cin >> B >> C;
			counter[B] += C;
			update(1, 1, CANDYSIZE, B,C);
		}
	}

	return 0;
