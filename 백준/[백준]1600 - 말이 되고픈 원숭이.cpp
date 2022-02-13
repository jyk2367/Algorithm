#include <bits/stdc++.h>
using namespace std;

int mtrx[202][202];
bool visited[202][202][32];//0은 인접, 0은 

int normaldx[] = {0,0,-1,1};
int normaldy[] = {-1,1,0,0};
int horsedx[] = {-2,-2,-1,-1,1,1,2,2};
int horsedy[] = {-1,1,-2,2,-2,2,-1,1};

int K, W, H;


int bfs(int x, int y) {
	int answer = 0;
	queue<pair<pair<int,int>,int>> q;
	q.push({ { x,y } ,0});
	visited[x][y][0] = true;

	while (!q.empty()) {
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			int nowx = q.front().first.first;
			int nowy = q.front().first.second;
			int Kcnt = q.front().second;
			q.pop();

			if (nowx == H - 1 && nowy == W - 1)
				return answer;

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowx+normaldx[dir];
				int ny = nowy+normaldy[dir];
				if (nx < 0 || ny < 0 || nx >= H || ny >= W)
					continue;
				if (visited[nx][ny][Kcnt])
					continue;
				if (mtrx[nx][ny] == 1)
					continue;
				q.push({ { nx,ny }, Kcnt});
				visited[nx][ny][Kcnt] = true;
			}
			if (Kcnt < K) {
				for (int dir = 0; dir < 8; dir++) {
					int nx = nowx + horsedx[dir];
					int ny = nowy + horsedy[dir];
					if (nx < 0 || ny < 0 || nx >= H || ny >= W)
						continue;
					if (visited[nx][ny][Kcnt+1])
						continue;
					if (mtrx[nx][ny] == 1)
						continue;
					q.push({ { nx,ny }, Kcnt + 1 });
					visited[nx][ny][Kcnt+1] = true;
				}
			}
		}
		answer++;
	}
	
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> K;

	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> mtrx[i][j];
		}
	}

	cout<<bfs(0, 0);

	return 0;
}
​