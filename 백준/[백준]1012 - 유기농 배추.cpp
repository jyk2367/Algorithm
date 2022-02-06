#include <bits/stdc++.h>
using namespace std;
int matrix[52][52];
bool visited[52][52];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int T, M, N, K;
int X, Y;

void func(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (matrix[nx][ny] == 0)
				continue;
			if (visited[nx][ny])
				continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;



	while (T--) {
		cin >> N >>M >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
				matrix[i][j] = 0;
			}
		}

		//N이 세로이므로 [N][M]
		while (K--) {
			cin >> X >> Y;
			matrix[X][Y] = 1;
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j]&&matrix[i][j] == 1) {
					func(i, j);
					answer++;
				}
			}
		}

		cout << answer<<"\n";
	}

	return 0;
}