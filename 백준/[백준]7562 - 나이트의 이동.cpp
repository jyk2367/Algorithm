#include <bits/stdc++.h>
#define pair pair<int,int>

using namespace std;

int T,I,answer;
bool visited[302][302];
int dx[] = { 1,2,-1,-2,1,2,-1,-2};
int dy[] = { 2,1,2,1,-2,-1,-2,-1};

void bfs(int x,int y, int &destX,int &destY) {
	queue<pair> q;
	q.push({ x,y });
	visited[x][y]=true;
	int cnt = 0;

	while (!q.empty()) {
		cnt++;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			pair p = q.front();
			q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nx = p.first+dx[dir];
				int ny = p.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= I || ny >= I)
					continue;
				if (visited[nx][ny])
					continue;
				if ((nx == destX) && (ny == destY)) {
					answer = min(answer, cnt);
					return;
				}
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >>T;

	while (T--) {
		int kX, kY;
		int destX, destY;

		memset(visited, 0, sizeof(visited));
		answer = 0x7fffffff;
		cin >> I;
		cin >> kX >> kY;
		cin >> destX >> destY;

		if (kX == destX && kY == destY)
			cout << 0 << "\n";
		else {
			bfs(kX, kY, destX, destY);
			cout << answer << "\n";
		}
		
	}

	
	return 0;
}