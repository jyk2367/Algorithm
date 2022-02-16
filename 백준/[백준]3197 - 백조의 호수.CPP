#include <bits/stdc++.h>
#define pair pair<int,int>
using namespace std;

int R, C;
char mtrx[1501][1501];
bool visited[1501][1501];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

queue<pair> nowWater;
queue<pair> nextWater;
queue<pair> nowSwan;
queue<pair> nextSwan;

vector<pair> swan;

void nowWaterBFS() {

	while (!nowWater.empty()) {
		int nowx = nowWater.front().first;
		int nowy = nowWater.front().second;
		nowWater.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowx + dx[dir];
			int ny = nowy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (mtrx[nx][ny] == 'X') {
				mtrx[nx][ny] = '.';
				nextWater.push({ nx, ny });
			}
		}
	}
}

bool swanBFS() {
	nowSwan.push(swan[0]);
	visited[swan[0].first][swan[0].second] = true;
	while (!nowSwan.empty()) {
		int nowx = nowSwan.front().first;
		int nowy = nowSwan.front().second;
		nowSwan.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowx + dx[dir];
			int ny = nowy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (visited[nx][ny])
				continue;
			visited[nx][ny] = true;

			if (mtrx[nx][ny] == '.') {
				nowSwan.push({ nx, ny });
			}
			if (mtrx[nx][ny] == 'X') {
				nextSwan.push({ nx,ny });
			}
			if (mtrx[nx][ny] == 'L')
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			mtrx[i][j] = tmp[j];
			if (mtrx[i][j] == 'L')
				swan.push_back({ i,j });
			if (mtrx[i][j] == '.' || mtrx[i][j] == 'L')
				nowWater.push({ i,j });
		}
	}


	int answer = 0;
	while (true) {
		if (swanBFS())
			break;

		//현재 물인 곳을 bfs로 돌면서 다음에 물이 될 놈들을 다른 큐에 집어넣음
		nowWaterBFS();

		answer++;

		//다음에 물이 될 큐를 현재 물인 큐로 옮김
		nowWater = nextWater;
		nowSwan = nextSwan;
		while (!nextWater.empty())
			nextWater.pop();
		while (!nextSwan.empty())
			nextSwan.pop();

	}

	cout << answer << "\n";

	return 0;
}