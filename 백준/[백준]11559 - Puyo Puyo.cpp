#include <bits/stdc++.h>
using namespace std;

char mtrx[13][7];
bool visited[13][7];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool bfs(int x, int y) {
	queue<pair<int, int>> mustExplode;//터트릴놈들 저장
	stack<pair<int, int>> stk;
	stk.push({ x,y });
	visited[x][y] = true;
	char startChar = mtrx[x][y];

	while (!stk.empty()) {
		int nowx = stk.top().first;
		int nowy = stk.top().second;
		mustExplode.push({ nowx,nowy });
		stk.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = nowx + dx[dir];
			int ny = nowy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny] == startChar) {
				stk.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}

	if (mustExplode.size() >= 4) {
		while (!mustExplode.empty()) {
			int nowx = mustExplode.front().first;
			int nowy = mustExplode.front().second;
			mtrx[nowx][nowy] = '.';
			mustExplode.pop();
		}
		return true;//지운게 있다면 true
	}
	return false;
}

bool drop() {
	bool state = false;//만약 아래로 떨어진게 없다면 false
	for (int j = 0; j < 6; j++) {
		int bottom = 11;
		for (int i = 11; i>=0; i--) {
			if (mtrx[i][j] == '.')
				continue;
			if (bottom!=i) {
				if (bottom != i)
					state = true;//만약 아래로 떨어진게 있다면 true
				mtrx[bottom][j] =mtrx[i][j];
				mtrx[i][j] = '.';
			}
			bottom--;
		}
	}

	return state;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> mtrx[i][j];
		}
	}

	int cnt = 0;

	while (true) {
		memset(visited, 0, sizeof(visited));
		bool state = false;
		//1.연쇄찾기->여러개 있으면 전부 없애기
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!visited[i][j] && mtrx[i][j] != '.') {
					if (bfs(i, j))
						state = true;//지운적이 한번이라도 있다면 true
				}
			}
		}
		if (state == true)//지웠으므로 cnt++
			cnt++;

		//2.떨구기
		if(drop()==false)
			break;
	}

	cout << cnt << "\n";

	return 0;
}