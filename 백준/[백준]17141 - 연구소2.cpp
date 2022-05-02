#include <bits/stdc++.h>
#define EMPTY 0
#define WALL 1
#define VIRUS 2

using namespace std;
int N,M;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
//bfs용
int mtrx[52][52];


//VIRUS칸 SELECT
vector<pair<int, int>> v;// 전체 바이러스 칸
vector<pair<int, int>> virus;//선택한 바이러스 칸
bool selected[12];

int answer = 0x7fffffff;
int EmptyCnt = 0;
int WallCnt = 0;


int bfs() {
	int ecnt = 0;
	bool visited[52][52];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		visited[virus[i].first][virus[i].second] = true;
		ecnt++;
	}

	int time = 0;

	while (!q.empty()) {
		if (ecnt == EmptyCnt) {
			return time;
		}
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			int nowX = q.front().first;
			int nowY = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowX + dx[dir];
				int ny = nowY + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (visited[nx][ny]|| mtrx[nx][ny] == WALL)
					continue;
				
				visited[nx][ny] = true;
				q.push({ nx,ny });
				ecnt++;
			}
		}
		time++;
		//모든 빈칸 완료되면  return
	}
	return 0x7fffffff;
}

void func(int k,int idx) {
	if (k == M) {
		answer=min(bfs(),answer);
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			virus.push_back({ v[i].first,v[i].second });
			func(k + 1,i);
			virus.pop_back();
			selected[i] = false;
		}
	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	EmptyCnt = N * N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i][j];
			if (mtrx[i][j] == VIRUS) {
				v.push_back({ i,j });
				mtrx[i][j] = 0;
			}
			if (mtrx[i][j] == WALL) {
				WallCnt++;
			}
		}
	}
	EmptyCnt -= WallCnt;
	func(0,0);

	if(answer==0x7fffffff)
		cout << -1 << "\n";
	else
		cout << answer << "\n";

	return 0;
}