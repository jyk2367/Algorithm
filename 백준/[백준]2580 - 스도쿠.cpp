#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int board[10][10];
bool mtrx[10][10];
bool rowAvail[10][10];
bool colAvail[10][10];
int cnt = 0;

bool func(int k) {
	if (k == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}

	int x = k / 9;
	int y = k % 9;
	if (board[x][y] != 0) {
		return func(k + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!mtrx[(x/3)*3 + (y / 3)][i] && !rowAvail[x][i] && !colAvail[y][i]) {
				mtrx[(x / 3) *3 +(y / 3)][i] = true;
				rowAvail[x][i] = true;
				colAvail[y][i] = true;
				board[x][y] = i;
				if (func(k + 1))
					return true;
				mtrx[(x / 3) *3  +(y / 3)][i] = false;
				rowAvail[x][i] = false;
				colAvail[y][i] = false;
				board[x][y] = 0;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				rowAvail[i][board[i][j]] = true;
				colAvail[j][board[i][j]] = true;
				mtrx[(i/3)*3+j/3][board[i][j]] = true;
			}
		}
	}

	func(0);

	return 0;
}