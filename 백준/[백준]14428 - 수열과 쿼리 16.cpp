#include <iostream>
#include <cmath>

#define ARRSIZE 100'000
using namespace std;

struct Node {
	int idx;
	int value;
	Node(int i, int v):idx(i),value(v){}
	Node():idx(0),value(0){}
};

int N,M;
int a, b, c;
Node arr[ARRSIZE];
Node* tree;

bool operator<(const Node &n1,const Node &n2) {
	if (n1.value == n2.value) {
		return n1.idx < n2.idx;
	}
	return n1.value < n2.value;
}

Node Init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[node]=min(Init(node * 2, start, mid),	Init(node * 2 + 1, mid + 1, end));
}

Node MinQuery(int node, int start, int end,int left,int right) {
	if (end<left||right<start) {
		return Node(0x7fff'ffff, 0x7fff'ffff);
	}

	if (left<=start&&end<=right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return min(MinQuery(node * 2, start, mid, left, right), MinQuery(node * 2 + 1, mid + 1, end, left, right));
}

void Update(int node, int start, int end, int target, int Value) {
	if (target < start || end < target) {
		return;
	}

	if (start == end) {
		tree[node].value = Value;
		return;
	}

	int mid = (start + end) / 2;
	Update(node * 2, start, mid, target, Value);
	Update(node * 2 + 1, mid + 1, end, target, Value);
	
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int height = (int)ceil(log2(N));
	int treeSize = 1 << (height + 1);
	tree = new Node[treeSize]();
	for (int i = 1; i <=N; i++) {
		arr[i].idx = i;
		cin >> arr[i].value;
	}
	Init(1,1,N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			//Update
			Update(1, 1, N, b, c);
			arr[b].value = c;
		}
		else {
			//Min
			if (b > c)
				swap(b, c);
			cout << MinQuery(1, 1, N, b, c).idx<<"\n";
		}
		
	}


	return 0;
}