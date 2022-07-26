#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int a, b, c;
long long arr[1'000'002];
long long* tree;

long long Sum(int node, int start,int end,int left,int right) {
	if (right < start || end < left) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

void Update(int node, int start, int end, int idx, long long dif) {
	if (idx < start || end < idx) {
		return;
	}
	tree[node] += dif;
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx, dif);
	Update(node * 2 + 1, mid + 1, end, idx, dif);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int height = (int)ceil(log2(N));
	int TreeSize = 1 << (height + 1);
	tree = new long long[TreeSize]();

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		if (a == 0) {
			if (b > c)
				swap(b, c);
			cout << Sum(1, 1, N, b, c)<<"\n";
		}
		else if (a == 1) {
			long long dif = c - arr[b];
			Update(1, 1, N, b, dif);
			arr[b] = c;
		}
	}

	delete[] tree;

	return 0;
}