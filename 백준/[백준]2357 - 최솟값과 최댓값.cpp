#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int a, b;
int arr[100'002];
int *maxTree,*minTree;

int maxInit(int node,int start,int end) {
	if (start == end) {
		return maxTree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return maxTree[node]=max(maxInit(node*2,start,mid), maxInit(node*2+1,mid+1,end));
}

int minInit(int node, int start, int end) {
	if (start == end) {
		return minTree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return minTree[node] = min(minInit(node * 2, start, mid), minInit(node * 2 + 1, mid + 1, end));
}


int maxQuery(int node,int start,int end,int left,int right) {
	if (start > right || end < left) {
		return 0;
	}

	if (left <=start&& end<= right) {
		return maxTree[node];
	}

	int mid = (start + end) / 2;
	return max(maxQuery(node * 2, start, mid, left, right), maxQuery(node * 2 + 1, mid + 1, end, left, right));
}

int minQuery(int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0x7fffffff;
	}

	if (left <= start && end <= right) {
		return minTree[node];
	}

	int mid = (start + end) / 2;
	return min(minQuery(node * 2, start, mid, left, right), minQuery(node * 2 + 1, mid + 1, end, left, right));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int height = (int)ceil(log2(N));
	int TreeSize = 1 << (height + 1);
	maxTree = new int[TreeSize]();
	minTree = new int[TreeSize]();
	maxInit(1,1,N);
	minInit(1,1,N);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout<<minQuery(1,1,N,a,b)<<" "<< maxQuery(1, 1, N, a, b) << "\n";
	}

	delete[]maxTree;
	delete[]minTree;

	return 0;
}