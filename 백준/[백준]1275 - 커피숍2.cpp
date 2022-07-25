#include <iostream>
#include <cmath>

#define MAX_ARRSIZE 100'002
using namespace std;

int N,Q;
long long arr[MAX_ARRSIZE];
long long* tree;

int x, y, a;
long long b;

long long Init(int node,int start,int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = Init(node * 2, start, mid) + Init(node * 2 + 1, mid + 1, end);
}

long long Sum(int node,int start,int end,int left,int right) {
	if (end<left || start>right) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

void Update(int node,int start,int end,int idx,long long dif) {
	if (idx < start || end < idx) {
		return;
	}
	tree[node] += dif;
	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx, dif);
	Update(node * 2 + 1, mid+1, end, idx, dif);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	int height = (int)ceil(log2(N));
	int treeSize = 1 << (height + 1);
	tree = new long long[treeSize]();

	for (int i = 1; i <=N; i++) {
		cin >> arr[i];
	}

	Init(1,1,N);

	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x > y)
			swap(x, y);
		cout<< Sum(1,1,N,x,y)<<"\n";
		long long dif = b - arr[a];
		Update(1,1,N,a,dif);
		arr[a] = b;
	}
	
	delete[] tree;

	return 0;
}