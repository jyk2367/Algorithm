#include <bits/stdc++.h>
#define LEFT -1
#define RIGHT 1

#define BODY -1
#define WALL 1
#define APPLE 2

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int N, K, L;
int mtrx[102][102];
queue<pair<int, int>> info;
//NESW
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int func() {
	int t=0;
	mtrx[1][1] = BODY;//뱀
	queue<pair<pair<int, int>,int>> q;
	queue<pair<int, int>> snake;
	snake.push({1,1});
	q.push({{ 1,1 },EAST });
	while (!q.empty()) {
		int nowX = q.front().first.first;
		int nowY = q.front().first.second;
		int nowD = q.front().second;
		q.pop();
		
		t++;

		int nextD=nowD;
		if (!info.empty()&&t == info.front().first) {
			nextD=(nowD+4+info.front().second)%4;
			info.pop();
		}

		int nextX = nowX + dx[nowD];
		int nextY = nowY + dy[nowD];
		if (mtrx[nextX][nextY] == WALL || mtrx[nextX][nextY] == BODY) {
			return t;
		}
		else if (mtrx[nextX][nextY] == APPLE) {
			mtrx[nextX][nextY] = BODY;
			snake.push({ nextX,nextY });
			q.push({{ nextX,nextY },nextD});
		}
		else {
			mtrx[snake.front().first][snake.front().second] = 0;
			snake.pop();
			mtrx[nextX][nextY] = BODY;
			snake.push({ nextX,nextY });
			q.push({ { nextX,nextY },nextD });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		mtrx[x][y] = APPLE;//apple
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char c;
		cin >> x >> c;
		info.push({ x, c == 'L' ? LEFT : RIGHT });//left : 0, right : 1
	}
	for (int i = 0; i < N+2; i++) {
		mtrx[0][i] = WALL;
		mtrx[i][0] = WALL;
		mtrx[N+1][i] = WALL;
		mtrx[i][N+1] = WALL;
	}

	cout<<func();

	return 0;
}