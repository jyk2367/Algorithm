#include <bits/stdc++.h>

using namespace std;

int R, C, T;
int A[52][52];

vector<pair<int, int>> airCleaner;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

void spread() {
	int tmp[52][52];
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] > 0) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int ni = i + dx[dir];
					int nj = j + dy[dir];

					if (ni < 0 || nj < 0 || ni >= R || nj >= C)
						continue;
					if (A[ni][nj] == -1)
						continue;
					tmp[ni][nj] += (A[i][j] / 5);
					cnt++;
				}
				tmp[i][j] += A[i][j] - cnt * (A[i][j] / 5);
			}
			else if (A[i][j] == -1)
				tmp[i][j] = -1;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

void work() {
	//반시계
	for (int i = airCleaner[0].first - 2; i >= 0; i--) {
		A[i + 1][0] = A[i][0];
	}
	for (int j = 1; j < C; j++) {
		A[0][j - 1] = A[0][j];
	}
	for (int i = 1; i <= airCleaner[0].first; i++) {
		A[i - 1][C - 1] = A[i][C - 1];
	}
	for (int i = C - 2; i >=1; i--) {
		A[airCleaner[0].first][i + 1] = A[airCleaner[0].first][i];
	}
	A[airCleaner[0].first][1] = 0;

	//시계
	for (int i = airCleaner[1].first + 2; i < R; i++) {
		A[i - 1][0] = A[i][0];
	}
	for (int i = 1; i < C; i++) {
		A[R - 1][i - 1] = A[R - 1][i];
	}
	for (int i = R-2; i >= airCleaner[1].first; i--) {
		A[i + 1][C - 1] = A[i][C - 1];
	}
	for (int j = C - 2; j >= 1; j--) {
		A[airCleaner[1].first][j + 1] = A[airCleaner[1].first][j];
	}
	A[airCleaner[1].first][1] = 0;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1) {
				airCleaner.push_back({ i,j });
			}
		}
	}
	int Time = 0;
	while (true) {
		if (Time == T)
			break;

		//미세먼지 확산
		spread();
		//공기청정기 작동
		work();

		Time++;
	}

	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] == -1)
				continue;
			answer += A[i][j];
		}
	}
	cout << answer << "\n";

	return 0;
}