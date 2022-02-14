#include <bits/stdc++.h>
#define pair pair<int,int>
using namespace std;

int N, M,P;
int S[10];//플레이어별 확장범위
int answer[10];//플레이어별 성 개수
queue<pair> castle[10];//플레이어 성
char mtrx[1002][1002];
bool visited[1002][1002];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


//큐가 다 비었다면
bool isAllQueueEmpty() {
	for (int i = 1; i <= P; i++) {
		if (castle[i].size() > 0)
			return false;
	}
	return true;
}

void bfs(int idx) {
	//S[idx]만큼 확장
	int T = 0;
	while (!castle[idx].empty()) {
		int PSIZE = castle[idx].size();
		T++;
		while(PSIZE--){
			int nowx = castle[idx].front().first;
			int nowy = castle[idx].front().second;
			castle[idx].pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowx + dx[dir];
				int ny = nowy + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				if (visited[nx][ny])
					continue;
				if (mtrx[nx][ny] != '.')
					continue;
				answer[idx]++;
				mtrx[nx][ny] = '0'+idx;
				visited[nx][ny] = true;
				castle[idx].push({ nx,ny });
			}
		}
		if (castle[idx].size() == 0)
			break;
		if (T == S[idx])
			break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> P;
	for (int i = 1; i <=P; i++) {
		cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			mtrx[i][j] = tmp[j];
			if (isdigit(tmp[j])) {
				castle[tmp[j] - '0'].push({ i,j });
				answer[tmp[j] - '0']++;
			}
		}
	}

	while (true) {
		//큐가 비었다면 break
		if (isAllQueueEmpty())
			break;
		for (int i = 1; i <=P; i++) {
			bfs(i);
		}
	}

	for (int i = 1; i <= P; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}