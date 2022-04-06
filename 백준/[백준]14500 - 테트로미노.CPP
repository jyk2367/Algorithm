#include <bits/stdc++.h>

using namespace std;

int N, M;
int mtrx[502][502];
bool visited[502][502];
int answer = 0;
vector<pair<int, int>> v;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
void func(int k, int x, int y, int sum) {
	if (k == 4) {
		answer = max(sum, answer);
		return;
	}
	visited[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (!visited[nx][ny]) {
			func(k + 1, nx,ny, sum + mtrx[x][y]);
		}
	}
	visited[x][y] = false;
}

void except(int x, int y) {
	//ㅏ
	if (x >= 0 && y >= 0 && x + 2 < N && y + 1 < M) {
		answer = max(answer, mtrx[x][y] + mtrx[x + 1][y] + mtrx[x + 2][y] + mtrx[x + 1][y + 1]);
	}
	//ㅓ
	if (x-1 >= 0 && y >= 0 && x + 1 < N && y + 1 < M) {
		answer = max(answer, mtrx[x][y] + mtrx[x - 1][y + 1] + mtrx[x + 1][y + 1] + mtrx[x][y + 1]);
	}
	//ㅗ
	if (x - 1 >= 0 && y >= 0 && x< N && y + 2 < M) {
		answer = max(answer, mtrx[x][y] + mtrx[x][y + 1] + mtrx[x][y + 2] + mtrx[x-1][y + 1]);
	}
	//ㅜ
	if (x  >= 0 && y >= 0 && x+1 < N && y + 2 < M) {
		answer = max(answer, mtrx[x][y] + mtrx[x][y + 1] + mtrx[x][y + 2] + mtrx[x + 1][y + 1]);
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			func(0, i, j, 0);
			except(i,j);
		}
	}

	cout << answer << "\n";


	return 0;
}