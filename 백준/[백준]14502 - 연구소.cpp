#include <bits/stdc++.h>
#define WALL 1
#define VIRUS 2
#define EMPTY 0
using namespace std;

//0 : 빈칸
//1 : 벽
//2 : 바이러스
//목표 : 벽 3개 세웠을 때 안전영역 크기
/*
0 : 빈칸
1 : 벽
2 : 바이러스
목표 : 벽 3개 세웠을 때 안전영역 크기
조합으로 벽3개 세우고 bfs돌아 남은영역 크기체크하면 끝
*/
int N, M;
int mtrx[10][10];
bool visited[10][10];
int answer;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
vector<pair<int, int>> virus;
int VSIZE;
int bfs() {
	vector<pair<int, int>> repair;
	queue<pair<int, int>> q;
	for (int i = 0; i < VSIZE; i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowX + dx[dir];
			int ny = nowY + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny] == WALL||mtrx[nx][ny]==VIRUS)
				continue;
			visited[nx][ny] = true;
			mtrx[nx][ny] = VIRUS;
			q.push({ nx,ny });
			repair.push_back({ nx,ny });
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mtrx[i][j] == EMPTY)
				cnt++;
		}
	}

	int RSIZE = repair.size();
	for (int i = 0; i <RSIZE; i++) {
		mtrx[repair[i].first][repair[i].second]=EMPTY;
		visited[repair[i].first][repair[i].second] = false;
	}
	
	return cnt;
}

void func(int k,int index) {
	if (k == 3) {
		answer=max(bfs(),answer);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mtrx[i][j] != EMPTY)
				continue;
			if (index > i * M + j)
				continue;
			mtrx[i][j] = WALL;
			func(k + 1,i*M+j);
			mtrx[i][j] = EMPTY;
		}
	}
}

int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
			if (mtrx[i][j] == VIRUS) {
				virus.push_back({ i,j });
			}
		}
	}
	VSIZE = virus.size();
	func(0,0);

	cout << answer << "\n";

	return 0;
}