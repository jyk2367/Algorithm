#include <iostream>
#include <cmath>

using namespace std;

int N,M;
int a, b, c;
int arr[100'002];
int* tree;

int Init(int node,int start,int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[node] = min(Init(node * 2, start, mid), Init(node * 2 + 1, mid + 1, end));
}

int MinQuery(int node, int start, int end,int left,int right) {
	if (end<left || start>right) {
		return 0x7fff'ffff;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return min(MinQuery(node * 2, start, mid, left, right), MinQuery(node * 2 + 1, mid+1, end, left, right));
}

void Update(int node, int start, int end, int idx, int value) {
	if (idx<start||end<idx) {
		return;
	}
	
	if (start == end) {
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx, value);
	Update(node * 2 + 1, mid+1, end, idx, value);

	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int height = (int)ceil(log2(N));
	int treeSize = 1 << (height+1);
	tree = new int[treeSize]();
	for (int i = 1; i <=N; i++) {
		cin >> arr[i];
	}
	Init(1, 1, N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			//update
			Update(1, 1, N, b, c);
			arr[b] = c;
		}
		else if (a == 2) {
			//최솟값 출력
			cout << MinQuery(1, 1, N, b, c)<<"\n";
		}
	}

	delete[] tree;

	return 0;
}