#include <bits/stdc++.h>
#define WALL -1
#define OPEN 0
using namespace std;
int N, L, R;
int mtrx[102][102];
bool visited[102][102];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0};

/*

index가 홀,홀이면 skip
index가 홀짝이면 상하, 짝홀이면 좌우 비교

*/

int openLine() {
	int cnt = 0;
	for (int i = 0; i < 2*N-1; i++) {
		for (int j = 0; j < 2 * N-1; j++) {
			if (i % 2 == 0 && j % 2 != 0) {
				int gap = abs(mtrx[i][j - 1] - mtrx[i][j + 1]);
				if (L <= gap && gap <= R) {
					mtrx[i][j] = OPEN;
					cnt++;
				}
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				int gap = abs(mtrx[i-1][j] - mtrx[i+1][j]);
				if (L <= gap && gap <= R) {
					mtrx[i][j] = OPEN;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

void bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int cnt = 0;
	vector<pair<int, int>> v;
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		if (nowX % 2 == 0 && nowY % 2 == 0) {
			cnt += mtrx[nowX][nowY];
			v.push_back({ nowX,nowY });
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowX + dx[dir];
			int ny = nowY + dy[dir];

			if (nx < 0 || ny < 0 || nx >= 2 * N - 1 || ny >= 2 * N - 1)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny] == WALL)
				continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	for (int i = 0; i < v.size(); i++) {
		mtrx[v[i].first][v[i].second]=cnt / v.size();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	
	cin >> N >> L >> R;

	for (int i = 0; i < 2 * N - 1; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			mtrx[i][j] = WALL;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i*2][j*2];
		}
	}


	int answer = 0;
	while (true) 
	{
		//국경선 열게 없다면 break
		if (openLine() == 0)
			break;
		answer++;

		//국경선 연 쪽들을 다 더해주고 분배
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i * 2][j * 2]) {
					bfs(i*2,j*2);
				}
			}
		}

		//국경선 초기화+ visited 초기화
		for (int i = 0; i < 2*N; i++) {
			for (int j = 0; j < 2*N; j++) {
				if (i % 2 != 0 || j % 2 != 0) {
					mtrx[i][j] = WALL;
				}
			}
		}

		memset(visited, false, sizeof(visited));
	}
	cout << answer << "\n";
	
}
