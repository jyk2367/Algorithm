#include <bits/stdc++.h>
#define EMPTY 0
#define ENEMY 1
#define CASTLE 2


using namespace std;

int N, M,D;
vector<int> archer;
int origin[16][16];
bool selected[16];
const int dx[] = {0,-1,1,0};
const int dy[] = {-1,0,0,1};
int answer = 0;

pair<int,int> bfs(int mtrx[][16],int index) {
	bool visited[16][16];
	memset(&visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ N,index });
	visited[N][index] = true;

	while (!q.empty()) {
		int QSIZE = q.size();

		for (int i = 0; i < QSIZE; i++) {
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
				visited[nx][ny] = true;
				if (mtrx[nx][ny] == CASTLE)
					continue;

				if ((abs(N-nx)+abs(index-ny))<=D&&mtrx[nx][ny] == ENEMY) {
					return { nx,ny };
				}
				else {
					q.push({ nx,ny });
				}
			}
		}
	}
	return { -1,-1 };
}

void killEnemy(int mtrx[][16],int& answer) {
	//각 archer에 대해 bfs를 돌아 나오는 generation에 맨 왼쪽(y값 최소) 적 선택
	vector<pair<int, int>> target;
	for (int i = 0; i < 3; i++) {
		target.push_back(bfs(mtrx,archer[i]));
	}
	//선택한 적 3개 한꺼번에 제거
	for (int i = 0; i < target.size(); i++) {
		if (target[i].first == -1) {
			continue;
		}
		if(mtrx[target[i].first][target[i].second]!=EMPTY) {
			mtrx[target[i].first][target[i].second] = EMPTY;
			answer++;
		}
	}
}

void moveEnemy(int mtrx[][16]) {
	for (int i = N-2; i>=0; i--) {
		for (int j = 0; j < M; j++) {
			mtrx[i + 1][j] = mtrx[i][j];
		}
	}
	for (int j = 0; j < M; j++) {
		mtrx[0][j] = EMPTY;
	}
}

bool isEnemyLeft(int mtrx[][16]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mtrx[i][j] == ENEMY)
				return true;
		}
	}
	return false;
}

void func(int k,int idx) {
	if (k == 3) {
		int mtrx[16][16];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mtrx[i][j]=origin[i][j];
			}
		}
		int result = 0;
		while (true) {
			killEnemy(mtrx,result);
			moveEnemy(mtrx);

			if (!isEnemyLeft(mtrx)) {
				break;
			}
		}
		answer = max(result, answer);


		return;
	}
	for (int i = idx; i < M; i++) {
		if (!selected[i]) {
			selected[i] = true;
			archer.push_back(i);
			func(k + 1, idx+1);
			archer.pop_back();
			selected[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> origin[i][j];
		}
	}
	for (int j = 0; j < M; j++) {
		origin[N][j] = CASTLE;
	}
	//1. [N][0~M-1]중에 궁수 3개 선택

	func(0,0);

	cout << answer << "\n";


}