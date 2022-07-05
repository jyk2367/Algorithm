#include <bits/stdc++.h>
#include <unordered_set>


using namespace std;


long long N;

void mulMatrix(long long matrix1[2][2],long long matrix2[2][2]) {
	long long outMatrix[2][2];
	outMatrix[0][0] = (matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0]) % 1000000;
	outMatrix[0][1] = (matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1]) % 1000000;
	outMatrix[1][0] = (matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0]) % 1000000;
	outMatrix[1][1] = (matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1]) % 1000000;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			matrix1[i][j] = outMatrix[i][j];
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	if (N == 0) {
		cout << 0 << "\n";
		return 0;
	}
	else if (N == 1) {
		cout << 1 << "\n";
		return 0;
	}
	else if (N == 2) {
		cout << 1 << "\n";
		return 0;
	}


	long long matrix[2][2] = { {1,0},{0,1} };
	long long v[2][2] = { {1,1},{1,0} };
	for (; N > 0; N = N >> 1) {
		if (N & 1) {
			mulMatrix(matrix,v);
		}
		mulMatrix(v, v);
	}
	cout << matrix[0][1] % 1000000 << "\n";
	

	return 0;
}