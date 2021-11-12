#include <iostream>
#include <queue>
using namespace std;
#define MAX 502
#define X first
#define Y second

int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char maze[MAX][MAX];
int vis[MAX][MAX];//전역변수로 설정하게되면 값들은 자동으로 초기화됨(전부 0으로). 따라서 코테에서는 전역변수로 풀어도 무방

int findpath();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//각각의 수들은 "붙어서" 주어지므로 char형태로 하는게 더 편해보인다.
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			int n = line[j] - '0';
			maze[i][j] = n;
		}
	}

	int n = findpath();
	cout << n;
	return 0;
}
/*
int findpath() {
	int count[502][502] = { 1, };
	queue<pair<pair<int, int>, int>> Q;
	vis[0][0] = 1;
	Q.push({{ 0,0 },1});
	while (!Q.empty()) {
		pair<pair<int, int>,int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			if (cur.X.X == N - 1 && cur.X.Y == M - 1)
				break;
			int nx = cur.X.X + dx[dir];
			int ny = cur.X.Y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && maze[nx][ny] == '1' && vis[nx][ny] == 0) {
				Q.push({{ nx,ny },cur.Y+1});
				vis[nx][ny] = 1;
				count[nx][ny] = cur.Y + 1;
			}
		}
	}
	return count[N - 1][M - 1];
}*/


int findpath() {
	int count[MAX][MAX] = { 1, };
	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {

			if (cur.X == N - 1 && cur.Y == M - 1)
				break;
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && maze[nx][ny] == 1 && vis[nx][ny] == 0) {
				Q.push({ nx,ny });
				vis[nx][ny] = 1;
				maze[nx][ny] = 0;
				count[nx][ny] = count[cur.X][cur.Y] + 1;
			}
		}
	}
	return count[N - 1][M - 1];
}