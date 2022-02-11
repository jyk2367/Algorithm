#include <bits/stdc++.h>
#define threepair  pair<pair<int,int>,bool> 
using namespace std;

bool mtrx[1001][1001];
//[0] : 벽 안뚫은상태
//[1] : 벽 뚫은상태
bool visited[1001][1001][2];
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int answer = 0;

int func(int x, int y) {
	queue<threepair> q;
	q.push({ {x,y},false });
	visited[x][y][0] = true;
	while (!q.empty()) {
		answer++;
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			threepair p = q.front();
			q.pop();
			int nowx = p.first.first;
			int nowy = p.first.second;
			bool wallbreak = p.second;
			if (nowx == N - 1 && nowy == M - 1)
				return answer;

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowx + dx[dir];
				int ny = nowy + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				//벽이면서 벽 안뚫었다면 큐에 넣기()
				if (mtrx[nx][ny] == 1 && wallbreak == false) {
					visited[nx][ny][1] = true;
					q.push({ { nx,ny }, true });
				}
				//길이면서 방문하지 않았다면
				////이전 상태 유지, 벽 뚫든 안뚫든 그상태 그대로
				else if (mtrx[nx][ny] == 0 && visited[nx][ny][wallbreak] == 0) {
					visited[nx][ny][wallbreak] = true;
					q.push({ { nx,ny }, wallbreak });
				}
			}
		}
	}
	//end에 못갔다면 결국 여기로나옴
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			mtrx[i][j] = tmp[j] - '0';
		}
	}
	cout<<func(0, 0);
	return 0;
}