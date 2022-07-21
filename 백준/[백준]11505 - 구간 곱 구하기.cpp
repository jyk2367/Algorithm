#include <iostream>
#include <cmath>

#define MOD 1'000'000'007

using namespace std;

int N, M, K;
int arr[1'000'002];
int a, b, c;
long long* tree;

long long Init(int node,int start,int end) {
	if(start==end){
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[node] = (Init(node * 2, start, mid) * Init(node * 2+1, mid + 1, end))% MOD;
}

long long mult(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 1;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return (mult(node * 2, start, mid, left, right) * mult(node * 2+1, mid + 1, end, left, right))% MOD;
}

long long Update(int node,int start,int end,int b,int c) {
	if (b < start || end < b) {
		return tree[node];
	}

	if (start == end) {
		return tree[node] = c;
	}

	int mid = (start + end) / 2;
	return tree[node] = (Update(node * 2, start, mid, b, c) * Update(node * 2 + 1, mid + 1, end, b, c)) % MOD;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	int height = (int)ceil(log2(N));
	int TreeSize = 1 << (height + 1);
	tree = new long long[TreeSize]();

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	Init(1,1,N);
	for (int i = 0; i < M+K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			//b번째 수를 c로 변경
			//b번째 수를 먼저 나눠주고 c를 곱해야 함
			arr[b] = c;
			Update(1, 1, N, b,c);
		}
		else if (a == 2) {
			//b부터 c까지의 곱을 구해 출력
			cout<<mult(1,1,N,b, c)<<"\n";
		}
	}

	delete[] tree;

	return 0;
}