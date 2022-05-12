#include <bits/stdc++.h>

using namespace std;

int ice[66][66];
int N, Q;
int L[1002];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
bool visited[66][66];

void Rotate(const int& si, const int& sj, const int& ei, const int& ej) {
	int temp[66][66];
	for (int i = si; i <= ei; i++) {
		for (int j = sj; j <= ej; j++) {
			temp[i][j] = ice[ei - (j - sj)][sj + i - si];
		}
	}

	for (int i = si; i <= ei; i++) {
		for (int j = sj; j <= ej; j++) {
			ice[i][j] = temp[i][j];
		}
	}

}

void removeIce() {
	vector<pair<int, int>> v;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {

			if (ice[x][y] > 0) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;
					if (ice[nx][ny] > 0) {
						cnt++;
					}
				}

				if (cnt < 3) {
					//한번에 다 지워야함
					v.push_back({ x,y });
				}

			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		ice[v[i].first][v[i].second]--;
	}

}

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	int cnt = 0;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		cnt++;

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowX + dx[dir];
			int ny = nowY + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[nx][ny])
				continue;
			if (ice[nx][ny] == 0)
				continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> Q;
	N = pow(2, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ice[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> L[i];
	}

	for (int idx = 0; idx < Q; idx++) {
		int nowL = L[idx];
		int LSIZE = pow(2, nowL);
		//2^L*2^L로 나누기

		//모든 부분격자 시계방향 90도 회전
		for (int i = 0; i < N; i += LSIZE) {
			for (int j = 0; j < N; j += LSIZE) {
				Rotate(i, j, i + LSIZE - 1, j + LSIZE - 1);
			}
		}

		//근처 얼음이 있는 칸 >=3이 아닌 칸은 얼음 양 -1
		removeIce();
	}

	//남은 얼음 합, 남은 얼음 중 가장 큰 덩어리가 차지하는 칸 개수
	//덩어리 없으면 0

	int answer = 0, lump = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += ice[i][j];
			if (!visited[i][j] && ice[i][j] != 0) {
				lump = max(bfs(i, j), lump);
			}
		}
	}

	cout << answer << " " << lump << "\n";

}