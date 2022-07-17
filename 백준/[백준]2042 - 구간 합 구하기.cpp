#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
long long* tree;
long long arr[1000001];
int N, M, K;
int a, b;
long long c;

long long Init(int node,int start,int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = Init(node * 2, start, mid) + Init(node * 2 + 1, mid + 1, end);
}

long long sum(int node,int start,int end,int left,int right) {
	if (end<left || start>right)
		return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node,int start,int end,int idx,long long diff) {
	if (idx<start || idx>end)
		return;
	tree[node] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid+1, end, idx, diff);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	int height = (int)ceil(log2(N));
	int treeSize = 1 << (height + 1);
	tree = new long long[treeSize];

	for (int i = 1; i <=N; i++) {
		cin >> arr[i];
	}

	Init(1,1,N);


	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c-arr[b];
			arr[b] = c;
			update(1,1,N,b,diff);
		}
		else if (a == 2) {
			cout << sum(1, 1, N, b, c) << "\n";
		}
	}

	
	delete[] tree;
    return 0;
}
