#include <bits/stdc++.h>
using namespace std;

int N,M,K;
bool visited[1001][1001][10];
int mtrx[1001][1001];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int func(int x, int y) {
	queue<pair<pair<int,int>,int>> q;
	q.push({ { x,y } ,0});
	visited[x][y][0] = true;
	int answer = 0;
	bool night = false;
	while (!q.empty()) {
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			int nowx = q.front().first.first;
			int nowy = q.front().first.second;
			int nowK = q.front().second;
			q.pop();
			if (nowx == N - 1 && nowy == M - 1) {
				return answer+1;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowx + dx[dir];
				int ny = nowy + dy[dir];

				if (nx < 0 || ny < 0||nx >= N || ny >= M)
					continue;
				if (mtrx[nx][ny] == 1&&nowK+1<=K&& !visited[nx][ny][nowK+1]) {
					if (!night) {
						q.push({ {nx,ny},nowK + 1 });
						visited[nx][ny][nowK + 1] = true;
					}
					else {
						//밤이라 벽을 못부수는 경우 기존값 그대로 유지
						q.push({ {nowx,nowy},nowK });
						visited[nowx][nowy][nowK] = true;
					}
				}
				if (mtrx[nx][ny] == 0&&!visited[nx][ny][nowK]) {
					q.push({ {nx,ny},nowK });
					visited[nx][ny][nowK] = true;
				}
			}
		}
		night ^= true;//낮밤변경
		answer++;
	}

	return -1;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >>M>>K;
	
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			mtrx[i][j] = tmp[j]-'0';
		}
	}

	cout << func(0, 0);


	return 0;
}