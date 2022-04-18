#include <bits/stdc++.h>

using namespace std;

int paper[4][4];
bool visited[4][4];
int N,M,answer;

void func(int k,int sum) {
	int x = k / M;
	int y = k % M;
	if (k >= N*M) {
		answer = max(answer, sum);
		return;
	}
	if (visited[x][y])
		func(k + 1,sum);
	else {
		int nextX, nextY;
		int value = paper[x][y];
		visited[x][y] = true;
		func(k + 1, sum + value);
		visited[x][y] = false;

		//아래
		for (int i = 1; i < N-x; i++) {
			nextX = x+i;
			nextY = y;
			value *= 10;
			value += paper[nextX][nextY];
			for (int j = 1; j <= i; j++)
				visited[x+j][nextY] = true;

			func(k + 1, sum + value);

			for (int j = 1; j <= i; j++)
				visited[x + j][nextY] = false;
		}

		value = paper[x][y];

		//오른쪽
		for (int i = 1; i < M-y; i++) {
			nextX = x;
			nextY = y+i;
			if (visited[nextX][nextY])
				return;
			value *= 10;
			value += paper[nextX][nextY];
			for (int j = 1; j <= i; j++)
				visited[nextX][y+j] = true;

			func(k + 1, sum + value);

			for (int j = 1; j <= i; j++)
				visited[nextX][y + j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
			paper[i][j] = tmp[j] - '0';
	}

	func(0, 0);
	
	cout << answer << "\n";
	
	return 0;
}