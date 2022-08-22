#include <iostream>

using namespace std;

int R, C;
int mtrx[22][22];
bool visited[27];
int answer;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };


void func(int k, int x, int y) {
	if (visited[mtrx[x][y] - 'A']) {
		answer = max(answer, k);
		return;
	}
	else {
		visited[mtrx[x][y] - 'A'] = true;

		for (int dir = 0; dir < 4; dir++) {
			int nextX = x + dx[dir];
			int nextY = y + dy[dir];

			if (nextX < 0 || nextY < 0 || nextX >= R || nextY >= C)
				continue;
			func(k + 1, nextX, nextY);
		}

		visited[mtrx[x][y] - 'A'] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			mtrx[i][j] = input[j];
		}
	}


	func(0, 0, 0);

	cout << answer << "\n";


	return 0;
}