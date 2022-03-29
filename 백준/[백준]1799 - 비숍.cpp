#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mtrx[12][12];
bool lu[25], ru[25];
int answer[2];

void func(int row, int col, int cnt, const int& number) {

	if (col >= N) {
		row++;
		if (col % 2 == 0)
			col = 1;
		else
			col = 0;
	}

	if (row >= N) {
		answer[number] = max(answer[number], cnt);
		return;
	}

	func(row, col + 2, cnt, number);

	if (mtrx[row][col] == 1 && ru[row + col] == 0 && lu[N + col - row] == 0) {
		ru[row + col] = lu[N + col - row] = 1;
		func(row, col + 2, cnt + 1, number);
		ru[row + col] = lu[N + col - row] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i][j];
		}
	}

	func(0, 0, 0, 0);
	func(0, 1, 0, 1);

	cout << answer[0] + answer[1] << "\n";

	return 0;
}