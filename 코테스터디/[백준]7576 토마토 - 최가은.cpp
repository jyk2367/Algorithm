#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 1002 //왜 502?
#define X first
#define Y second

int N, M;
int box[MAX][MAX];
int cnt[MAX][MAX];//vis보다 cnt가 의미상 맞는듯함
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool state = false;
	// M행 N열이므로 입력값을 기존에서 반대로 받는다
	cin >> M >> N;
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			cnt[i][j] = -1;
			if (box[i][j] == 1) {
				Q.push({ i,j });
				cnt[i][j] = 0;
			}
		}
	}


	while (!Q.empty()) {//bfs
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && cnt[nx][ny] == -1 && box[nx][ny] == 0) {//cnt[ny][nx]에서 cnt[nx][ny]
				Q.push({ nx,ny });
				box[nx][ny] = 1;
				cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cout << box[i][j] << " ";
			//cout << cnt[i][j] << " ";
			result = max(result, cnt[i][j]);
		}
		//cout << "\n";
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0 && cnt[i][j] == -1) {
				result = -1;
			}
		}
	}

	cout << result;
	return 0;
}