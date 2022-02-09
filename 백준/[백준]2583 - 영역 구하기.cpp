#include <bits/stdc++.h>
#define pair pair<int,int> 
using namespace std;

int N, M, K;
bool mtrx[102][102];
bool visited[102][102];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int func(int x, int y) {
	queue< pair> q;
	q.push({ x,y });
	visited[x][y] = true;
	int cnt = 0;
	while (!q.empty()) {
		pair p = q.front();
		q.pop();
		cnt++;

		for (int dir = 0; dir < 4; dir++) {
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny])
				continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 5 7 3
	cin >> M >> N >> K;
	int x1, y1, x2, y2;
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i <y2; i++) {
			for (int j = x1; j <x2; j++) {
				mtrx[i][j] = true;
			}
		}
	}
	int cnt = 0;
	vector<int> answer;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && mtrx[i][j] == false) {
				cnt++;
				answer.push_back(func(i, j));
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << cnt << "\n";
	for (int a : answer) {
		cout << a << " ";
	}

	return 0;
}