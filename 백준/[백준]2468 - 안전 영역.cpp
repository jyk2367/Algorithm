#include <bits/stdc++.h>
#define pair pair<int,int> 
using namespace std;

int N;
int mtrx[102][102];
bool visited[102][102];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void func(int x,int y,int &height) {
	queue<pair> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		pair p = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny]<=height)
				continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	int MX = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i][j];
			MX = max(MX, mtrx[i][j]);
		}
	}

	int R = 100;
	int answer = 0;
	while (MX!=-1) {
		memset(visited, 0, sizeof(visited));

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]&&mtrx[i][j]>MX) {
					cnt++;
					func(i, j, MX);
				}
			}
		}

		answer = max(answer, cnt);
		MX--;
	}
	cout << answer << "\n";

	return 0;
}