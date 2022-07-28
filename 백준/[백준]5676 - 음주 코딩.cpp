#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K;
char C;
int I, V;
int arr[100'002];
int* tree;

int getSign(int num) {
	if (num > 0) {
		return 1;
	}
	else if (num < 0) {
		return -1;
	}
	else
		return 0;
}

int Init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[node] = Init(node * 2, start, mid) * Init(node * 2 + 1, mid + 1, end);
}

int Update(int node, int start, int end, int idx, int value) {
	if (idx < start || end < idx) {
		return tree[node];
	}

	if (start == end) {
		return tree[node] = getSign(value);
	}

	int mid = (start + end) / 2;

	return tree[node] = Update(node * 2, start, mid, idx, value) * Update(node * 2 + 1, mid + 1, end, idx, value);
}

int Mul(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 1;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return Mul(node * 2, start, mid, left, right) * Mul(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int height = (int)ceil(log2(100'000));
	int treeSize = 1 << (height + 1);
	tree = new int[treeSize]();

	while (cin >> N >> K) {
		vector<char> answer;
		for (int i = 1; i <= N; i++) {
			int input;
			cin >> input;
			arr[i] = getSign(input);
		}
		Init(1, 1, N);

		for (int i = 0; i < K; i++) {
			cin >> C >> I >> V;

			if (C == 'C') {
				//Update
				Update(1, 1, N, I, V);
				arr[I] = getSign(V);
			}
			else if (C == 'P') {
				//Mul
				int result = Mul(1, 1, N, I, V);
				if (result == 1) {
					answer.push_back('+');
				}
				else if (result == 0) {
					answer.push_back('0');
				}
				else {
					answer.push_back('-');
				}
			}
		}

		int answerSize = answer.size();
		for (int i = 0; i < answerSize; i++) {
			cout << answer[i];
		}
		cout << "\n";

	}

	delete[] tree;

	return 0;
}