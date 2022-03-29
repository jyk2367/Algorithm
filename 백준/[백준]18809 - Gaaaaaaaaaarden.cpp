#include <bits/stdc++.h>
using namespace std;

int mtrx[52][52];
bool selected[12];
int G, R;
int N, M;
vector<pair<int, int>> plant, green,red;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

int answer = 0;


int BFS() {
	int cnt = 0;
	int Gtime[52][52],Rtime[52][52];
	bool flower[52][52];
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			Gtime[i][j] = -1;
			Rtime[i][j] = -1;
			flower[i][j] = 0;
		}
	}
	queue<pair<int, int>> gq, rq;
	for (int i = 0; i < G; i++) {
		Gtime[green[i].first][green[i].second] = 0;
		gq.push({ green[i].first ,green[i].second });
	}
	for (int i = 0; i < R; i++) {
		Rtime[red[i].first][red[i].second] = 0;
		rq.push({ red[i].first ,red[i].second });
	}

	int time = 0;

	//gq, rq 동시에 bfs
	while (!gq.empty()&&!rq.empty()) {
		int GQSIZE = gq.size();
		int RQSIZE = rq.size();
		time++;
		for (int i = 0; i < GQSIZE; i++) {
			int nowX = gq.front().first;
			int nowY = gq.front().second;
			gq.pop();
			if (flower[nowX][nowY])
				continue;
			for (int dir = 0; dir < 4; dir++) {
				int nextX = nowX + dx[dir];
				int nextY = nowY + dy[dir];

				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
					continue;
				//호수 continue
				if (mtrx[nextX][nextY]==0)
					continue;
				//한번이라도 방문했다면 continue;
				if (Gtime[nextX][nextY] > -1)
					continue;
				//이미 빨간색이 있다면 time이 다른 것이므로 continue
				if (Rtime[nextX][nextY] > -1)
					continue;

				Gtime[nextX][nextY] = time;
				gq.push({ nextX,nextY });
			}
		}

		for (int i = 0; i < RQSIZE; i++) {
			int nowX = rq.front().first;
			int nowY = rq.front().second;
			rq.pop();
			if (flower[nowX][nowY])
				continue;
			for (int dir = 0; dir < 4; dir++) {
				int nextX = nowX + dx[dir];
				int nextY = nowY + dy[dir];

				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
					continue;
				if (mtrx[nextX][nextY]== 0)
					continue;
				if (Rtime[nextX][nextY] > -1)
					continue;
				//만약 초록쪽에서 아직 접근하지 않은 상태라면
				//다음위치의 초록배양액이 동시에 도달하는 경우 꽃
				if (Gtime[nextX][nextY] == time) {
					flower[nextX][nextY] = true;
					cnt++;
				}
				else if (Gtime[nextX][nextY] == -1) {
					rq.push({ nextX,nextY });
				}
				Rtime[nextX][nextY] = time;
			
			}
		}
	}

	
	return cnt;
}

void func(int k,int g,int r) {
	if (G < green.size()||R<red.size()) {
		return;
	}
	if (G == green.size() && R == red.size()) {
		answer=max(BFS(),answer);
		return;
	}
	if (k == plant.size()) {
		return;
	}
	

	func(k + 1,g,r);

	if (g > 0) {
		green.push_back(plant[k]);
		func(k + 1,g-1,r);
		green.pop_back();
	}

	if (r > 0) {
		red.push_back(plant[k]);
		func(k + 1,g,r-1);
		red.pop_back();
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M>>G>>R;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
			if (mtrx[i][j] == 2) {
				plant.push_back({ i,j });
			}
		}
	}

	func(0,G,R);

	cout << answer << "\n";
	
	return 0;
}