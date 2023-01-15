#include <bits/stdc++.h>
#define EMPTY '.'
#define WATER '*'
#define ROCK 'X'
#define BEAVERSDEN 'D'
#define HEDGEHOG 'S'
#define IIPair pair<int,int>
#define X first
#define Y second
using namespace std;

int R, C;
char Map[52][52];
// 고슴도치 위치
queue<IIPair> hhPos;
// 물 위치
queue<IIPair> waterPos;

bool wVisited[52][52];
bool hVisited[52][52];
const int dx[] = {-1,0,0,1};
const int dy[] = {0,1,-1,0};

int bfs() {
	int count = 0;
	//물 1번 전부 이동 후 고슴도치 이동가능 다넣기
	while (!hhPos.empty()||!waterPos.empty()) {
		int WQSIZE = waterPos.size();
		for (int i = 0; i < WQSIZE; i++) {
			int nowX = waterPos.front().X;
			int nowY = waterPos.front().Y;
			waterPos.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nextX = nowX + dx[dir];
				int nextY = nowY + dy[dir];

				if (0 > nextX || 0 > nextY || nextX >= R || nextY >= C)
					continue;
				
				if (wVisited[nextX][nextY])
					continue;

				wVisited[nextX][nextY] = true;

				if (Map[nextX][nextY]!=EMPTY)
					continue;
				Map[nextX][nextY] = WATER;
				waterPos.push({ nextX,nextY });
			}
		}
		
		int HHQSIZE = hhPos.size();
		for (int i = 0; i < HHQSIZE; i++) {
			int nowX = hhPos.front().X;
			int nowY = hhPos.front().Y;
			hhPos.pop();

			if (Map[nowX][nowY] == BEAVERSDEN) {
				return count;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nextX = nowX + dx[dir];
				int nextY = nowY + dy[dir];

				if (0 > nextX || 0 > nextY || nextX >= R || nextY >= C)
					continue;

				if (hVisited[nextX][nextY])
					continue;

				hVisited[nextX][nextY] = true;

				if (Map[nextX][nextY] == EMPTY || Map[nextX][nextY] == BEAVERSDEN) {
					hhPos.push({ nextX,nextY });
				}
			}
		}
		count++;
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == HEDGEHOG) {
				hhPos.push({ i,j });
				hVisited[i][j] = true;
			}
			else if (Map[i][j] == WATER) {
				waterPos.push({ i,j });
				wVisited[i][j] = true;
			}
		}
	}

	int result=bfs();

	if (result == -1)
		cout << "KAKTUS" << "\n";
	else
		cout << result << "\n";
	

	return 0;
}