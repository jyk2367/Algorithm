#include <bits/stdc++.h>
#define pair  pair<int,int> 
using namespace std;
int N, M;
int mtrx[302][302];
bool visited[302][302];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void melt() {
	int temp[301][301];
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			temp[x][y] = mtrx[x][y];

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (mtrx[x][y]) {
				int minusmelt = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (temp[nx][ny] == 0)
						minusmelt++;
				}
				if ((mtrx[x][y] - minusmelt) <= 0) mtrx[x][y] = 0; 
				else mtrx[x][y] = mtrx[x][y] - minusmelt; 
			}
		}
	}
}

void bfs(int x,int y) {
	queue<pair> q;
	q.push({ x,y });
	visited[x][y]=true;

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy =q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = nowx + dx[dir];
			int ny = nowy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny]==0)
				continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
		}
	}
	int answer = 0;
	while (true) {
		memset(visited, 0, sizeof(visited));
		melt();

		answer++;
		int cnt = 0;
		bool check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && mtrx[i][j] > 0) {
					cnt++;
					if (cnt == 2) {
						check = true;
						break;
					}
					bfs(i, j);
				}
			}
			if (cnt == 2)
				break;
		}
		if (check){
			cout << answer << "\n";
			break;
		}
		if (cnt == 0) {
			cout << 0 << "\n";
			break;
		}
	}

	return 0;
}