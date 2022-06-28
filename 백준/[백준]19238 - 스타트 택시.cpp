#include <bits/stdc++.h>

#define EMPTY 0
#define WALL 1
#define PASSENGER 2

using namespace std;

int fuel;
int mtrx[22][22];
bool visited[22][22];
int N, M;
pair<int, int> taxi;
pair<int, int> nowpsgr;

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

struct Passenger {
	int dx;
	int dy;
};
Passenger ps[22][22];

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

pair<int,int> PassengerBfs() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}

	deque<pair<int, int>> dq;
	dq.push_back(taxi);
	visited[taxi.first][taxi.second] = true;

	int Time = 0;
	while (!dq.empty()) {
		int DQSIZE = dq.size();
		for (int i = 0; i < DQSIZE; i++) {
			int nowX = dq.front().first;
			int nowY = dq.front().second;
			dq.pop_front();

			if (mtrx[nowX][nowY] == PASSENGER) {
				fuel -= Time;
				taxi = { nowX,nowY };
				mtrx[nowX][nowY] = EMPTY;
				return {nowX,nowY};
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowX + dx[dir];
				int ny = nowY + dy[dir];

				if (nx<1 || ny<1 || nx>N || ny>N)
					continue;
				if (visited[nx][ny])
					continue;
				visited[nx][ny] = true;
				if (mtrx[nx][ny]==WALL)
					continue;

				dq.push_back({ nx,ny });
			}
		}
		Time++;
		sort(dq.begin(), dq.end(),comp);
	}

	return {-1,-1};
}

bool DriveBfs() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}

	Passenger& nowPs = ps[nowpsgr.first][nowpsgr.second];
	queue<pair<int, int>> q;
	q.push(taxi);
	visited[taxi.first][taxi.second] = true;

	int Time = 0;
	while (!q.empty()) {
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			int nowX = q.front().first;
			int nowY = q.front().second;
			q.pop();

			if (nowX== nowPs.dx&&nowY== nowPs.dy) {
				fuel -= Time;
				if (fuel < 0)
					return false;
				fuel += Time * 2;
				taxi = { nowX,nowY };
				return true;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowX + dx[dir];
				int ny = nowY + dy[dir];

				if (nx<1 || ny<1 || nx>N || ny>N)
					continue;
				if (visited[nx][ny])
					continue;
				visited[nx][ny] = true;
				if (mtrx[nx][ny] == WALL)
					continue;

				q.push({ nx,ny });
			}
		}
		Time++;
	}


	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> fuel;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			cin >> mtrx[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	taxi = {x,y};

	for (int i = 0; i < M; i++) {
		int sx, sy;
		cin >> sx >> sy;
		mtrx[sx][sy] = PASSENGER;
		cin >> ps[sx][sy].dx >> ps[sx][sy].dy;
	}

	for (int i = 0; i < M; i++) {
		nowpsgr=PassengerBfs();

		//승객을 못찾거나, 승객을 찾긴 찾았지만 연료가 바닥난 경우
		if (nowpsgr.first == -1 && nowpsgr.second == -1||fuel<0) {
			cout << -1 << "\n";
			return 0;
		}
		//승객을 목적지까지 데려다주는걸 실패하거나, 연료가 그전에 바닥난 경우
		if (!DriveBfs()) {
			cout<<-1<<"\n";
			return 0;
		}
	}
	
	cout << fuel << "\n";
	return 0;
}
