#include <bits/stdc++.h>
#include <unordered_set>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int N, M, K;
int mtrx[22][22];
bool visited[22][22];

int dir = EAST;		//북동남서
int dice[] = {2,4,1,3,5,6};
pair<int, int> sp = { 1,1 };
int score = 0;

//북 동 남 서
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void Init() {
	cin >> N >> M >> K;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=M; j++) {
			cin >> mtrx[i][j];
		}
	}
}

// 방향 반시계
void rotateDirCClock() {
	dir = (dir + 3) % 4;
}

// 방향 시계
void rotateDirClock() {
	dir = (dir + 1) % 4;
}

// 방향 반대
void reverseDir() {
	dir = (dir + 2) % 4;
}

void rollDice(){
	if (dir == EAST) {
		int tmp = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = tmp;
	}
	else if (dir == WEST) {
		int tmp = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == NORTH) {
		int tmp = dice[5];
		dice[5] = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = tmp;
	}
	else if (dir == SOUTH) {
		int tmp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = tmp;
	}
}


void moveDice() {
	//이동방향으로 한칸 굴리기
	//이동방향에 칸이 없으면 반대로해서 한칸 굴러감
	int nx=sp.first + dx[dir];
	int ny=sp.second + dy[dir];

	if (nx<1 || ny<1 || nx>N || ny>M){
		reverseDir();
		nx = sp.first + dx[dir];
		ny = sp.second + dy[dir];
	}

	rollDice();

	sp.first = nx;
	sp.second = ny;

}

int GetBottom() {
	return dice[5];
}

int BFS() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	q.push(sp);
	visited[sp.first][sp.second] = true;
	int startScore = mtrx[sp.first][sp.second];
	int cnt = 0;

	while (!q.empty()) {
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			int nowX = q.front().first;
			int nowY = q.front().second;
			q.pop();

			if (mtrx[nowX][nowY] == startScore) {
				cnt++;
			}

			for (int d = 0; d < 4; d++) {
				int nx = nowX + dx[d];
				int ny = nowY + dy[d];

				if (nx<1 || ny<1 || nx>N || ny>M)
					continue;

				if (visited[nx][ny])
					continue;
				visited[nx][ny] = true;
				if (mtrx[nx][ny] == startScore) {
					q.push({ nx,ny });
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Init();

	while (K-- > 0) {
		moveDice();

		int A = GetBottom();
		int B = mtrx[sp.first][sp.second];
		int C = BFS();
		
		score += B * C;
		if (A > B) {
			rotateDirClock();
		}
		else if (A < B) {
			rotateDirCClock();
		}
	}

	cout << score << "\n";
	
	return 0;
}
