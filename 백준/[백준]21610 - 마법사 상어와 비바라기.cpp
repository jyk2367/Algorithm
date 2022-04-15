#include <bits/stdc++.h>

using namespace std;
const int dx[] = {0,0,-1,-1,-1,0,1,1,1};
const int dy[] = {0,-1,-1,0,1,1,1,0,-1};
const int diagonal_dx[] = {-1,-1,1,1};
const int diagonal_dy[] = {-1,1,-1,1};

int basket[52][52];
bool visited[52][52];
int D[102],S[102];
int N,M;
queue<pair<int, int>> cloud;

void makeCloud() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (basket[i][j] >= 2&&visited[i][j]==false) {
				basket[i][j] -= 2;
				cloud.push({ i,j });
			}
			visited[i][j] = false;
		}
	}
}

void copyWater() {
	int CSIZE = cloud.size();
	for (int i = 0; i < CSIZE; i++) {
		int nowX = cloud.front().first;
		int nowY = cloud.front().second;
		cloud.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowX + diagonal_dx[dir];
			int ny = nowY + diagonal_dy[dir];

			if(nx<=0||ny<=0||nx>N||ny>N)
				continue;
			
			if (basket[nx][ny] > 0)
				basket[nowX][nowY]++;
		}
	}
}

void moveCloud(int idx) {
	int CSIZE = cloud.size();
	for (int i = 0; i < CSIZE; i++) {
		int nowX = cloud.front().first;
		int nowY = cloud.front().second;
		cloud.pop();

		int dir = D[idx];
		int dist = S[idx];
		int nx = (nowX + dx[dir] * dist);
		int ny = (nowY + dy[dir] * dist);

		while (nx <= 0) {
			nx += N;
		}
		while (ny <= 0) {
			ny += N;
		}
		if (nx > N)
			nx %= N;
		if (nx == 0)
			nx = N;
		if (ny > N)
			ny %= N;
		if (ny == 0)
			ny = N;

		if (visited[nx][ny])
			continue;
		basket[nx][ny]++;
		cloud.push({ nx,ny });
		visited[nx][ny] = true;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>M;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			cin >> basket[i][j];
		}
	}

	for (int i = 1; i <=M; i++) {
		cin >> D[i] >> S[i];
	}

	cloud.push({ N,1 });
	cloud.push({ N,2 });
	cloud.push({ N-1,1 });
	cloud.push({ N-1,2 });

	int moveCnt = M;
	int cnt = 0;
	while (cnt<moveCnt) {
		cnt++;
		moveCloud(cnt);
		copyWater();
		makeCloud();
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += basket[i][j];
		}
	}
	cout << answer << "\n";
		
	return 0;
}
​