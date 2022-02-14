#include <bits/stdc++.h>
#define pair pair<int,int>
using namespace std;

queue<pair> swt[102][102];//각 방마다 있는 스위치
bool light[102][102];//빛 on off
bool canGo[102][102];
bool visited[102][102];//방문 유 무
int answer;//불 켜진곳 개수

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int N,M;

void bfs(int x, int y) {
	queue<pair> q;
	q.push({ x,y });
	visited[x][y] = true;
	light[x][y] = true;
	answer++;
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		
		if (light[nowx][nowy] == false)
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowx + dx[dir];
			int ny = nowy + dy[dir];
			
			if (nx<1 || ny<1 || nx>N || ny>N)
				continue;
			if (canGo[nx][ny])
				continue;
			canGo[nx][ny] = true;//갈수 있는 곳임을 표시

			if (light[nx][ny]) {//갈수있으면서 빛이 있는 경우
				q.push({ nx,ny });
			}
		}


		while (!swt[nowx][nowy].empty()) {
			int swtX = swt[nowx][nowy].front().first;
			int swtY = swt[nowx][nowy].front().second;
			swt[nowx][nowy].pop();
			if (visited[swtX][swtY])
				continue;
			if (light[swtX][swtY] == false) {
				light[swtX][swtY] = true;
				answer++;
			}
			else
				continue;
			
			if (canGo[swtX][swtY]) {
				q.push({ swtX,swtY });
				visited[swtX][swtY] = true;
			}

		}
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	while (M--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		swt[x][y].push({ a,b });
	}

	bfs(1, 1);
	
	cout << answer;

	return 0;
}