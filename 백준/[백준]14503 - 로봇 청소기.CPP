#include <bits/stdc++.h>
#define PAIR pair<pair<int,int>,int>

using namespace std;

int N, M;
int mtrx[52][52];
bool visited[52][52];
int r, c, d;
int cleanCnt = 0;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};
void bfs() {
	queue<PAIR> q;
	q.push({{ r,c }, d});
	
	int state_2a_Cnt = 0;
	while (!q.empty()) {
		int nowR = q.front().first.first;
		int nowC = q.front().first.second;
		int nowD = q.front().second;
		q.pop();
		
		//1
		if (visited[nowR][nowC] == false && mtrx[nowR][nowC] == 0) {
			visited[nowR][nowC] = true;
			cleanCnt++;
		}

		//2a
		int leftD = (nowD + 3) % 4;
		int backD = (nowD + 2) % 4;
		int leftR = nowR + dr[leftD];
		int leftC = nowC + dc[leftD];

		if (visited[leftR][leftC] == false&&mtrx[leftR][leftC]==0) {
			q.push({ {leftR,leftC},leftD });
			state_2a_Cnt = 0;
		}
		else {
			if (state_2a_Cnt < 4) {
				q.push({ {nowR,nowC},leftD });
				state_2a_Cnt++;
			}
			else {//2b
				int backR = nowR + dr[backD];
				int backC = nowC + dc[backD];

				if (mtrx[backR][backC] == 1) {
					break;
				}
				else {
					q.push({ {backR,backC} ,nowD });
				}
				state_2a_Cnt = 0;
			}
		}
	}
}

int main(void) {
	
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
		}
	}

	bfs();

	cout << cleanCnt << "\n";

	return 0;
}