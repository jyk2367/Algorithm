#include <bits/stdc++.h>
#define pair pair<int,int>
using namespace std;

int T,H,W;
char mtrx[105][105];
bool visited[105][105];
bool key[27];//key, 대문자로
queue<pair> q;
list<pair> door;
int answer;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void bfs(pair p) {
	q.push(p);
	visited[p.first][p.second] = true;

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = nowx + dx[dir];
			int ny = nowy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= H+3 || ny >= W+3)
				continue;
			if (visited[nx][ny])
				continue;
			if (mtrx[nx][ny] == '*')
				continue;
			if (mtrx[nx][ny] == '$') {
				visited[nx][ny] = true;
				q.push({nx,ny});
				answer++;
				continue;
			}
			
			if (mtrx[nx][ny] == '.') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (isupper(mtrx[nx][ny])) {
				//문인데 열쇠가 있는 경우 : 큐에 넣음
				if (key[mtrx[nx][ny] - 'A']) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				//문인데 열쇠가 없는 경우 : door에 넣음
				else
					door.push_back({ nx,ny });
			}
			else if (islower(mtrx[nx][ny])) {
				//열쇠인 경우 : 열리는 door을 큐로 넣어주고, 혹시 열쇠뒤에 공간이 있을 수 있으므로 열쇠위치도 큐에 넣어줌
				key[mtrx[nx][ny] - 'a'] = true;

				for (list<pair>::iterator it = door.begin(); it != door.end();) {
					int doorX = (*it).first;
					int doorY = (*it).second;

					if (key[mtrx[doorX][doorY] - 'A']) {
						visited[doorX][doorY] = true;
						q.push({ doorX, doorY });
						it = door.erase(it);
					}
					else
						it++;
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
	
	cin >> T;

	while (T--) {
		answer = 0;
		memset(visited, 0, sizeof(visited));
		memset(key, 0, sizeof(key));
		door.clear();

		cin >> H >> W;

		for (int i = 0; i < H + 3; i++) {
			for (int j = 0; j < W + 3; j++) {
				mtrx[i][j] = '.';
			}
		}

		for (int i = 1; i <=H; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 1; j <=W; j++) {
				mtrx[i][j] = tmp[j-1];
			}
		}
		string tmp;
		cin >> tmp;
		if (tmp != "0") {
			for (int i = 0; i < tmp.length(); i++) {
				key[tmp[i] - 'a'] = true;
			}
		}

		bfs({ 0,0 });
		cout << answer << "\n";
	}
	

	return 0;
}