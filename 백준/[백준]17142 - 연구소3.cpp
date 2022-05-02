#include <bits/stdc++.h>
#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define PAIR pair<int, int>
using namespace std;

vector<PAIR> virus;
vector<PAIR> selectedVirus;

int N,M;
int mtrx[52][52];

bool selected[2501];

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
int answer=0x7fffffff;
int WALLCNT = 0;
int SPREADALL;

int bfs() {
	bool visited[52][52];
	memset(visited, 0, sizeof(visited));

	int cnt = 0;//N*N에서 WALL빼고 전체VIRUS-SELVIRUS크기빼고
	queue<PAIR> q;
	for (PAIR p : selectedVirus) {
		q.push(p);
		visited[p.first][p.second]=true;
		cnt++;
	}

	int Time = 0;
	while (!q.empty()) {
		if (cnt == SPREADALL) {
			return Time;
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
				if (visited[nx][ny])
					continue;
				visited[nx][ny] = true;

				if (mtrx[nx][ny] == WALL)
					continue;

				if(mtrx[nx][ny] != VIRUS)
					cnt++;
				q.push({ nx,ny });
			}
		}
		Time++;
	}
	return 0x7fffffff;
}

void func(int k,int idx) {
	if (k == M) {
		answer = min(bfs(), answer);
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			selectedVirus.push_back(virus[i]);
			func(k + 1, i);
			selectedVirus.pop_back();
			selected[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i][j];
			if (mtrx[i][j] == WALL) {
				WALLCNT++;
			}
			if (mtrx[i][j] == VIRUS) {
				virus.push_back({ i,j });
			}
		}
	}
	SPREADALL = (N * N) - WALLCNT - (virus.size() - M);
	func(0,0);
	
	if (answer == 0x7fffffff)
		cout << -1 << "\n";
	else
		cout << answer << "\n";


	return 0;
}
