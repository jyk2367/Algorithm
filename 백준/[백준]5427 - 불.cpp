#include <bits/stdc++.h>
#define pair pair<int,int>
using namespace std;
char mtrx[1002][1002];
bool visited[1002][1002];
int T, W, H,answer;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool func(queue<pair> & fire, queue<pair>& man) {
	answer = 0;
	while (!man.empty()) {
		//불 이동
		int FSIZE = fire.size();
		for (int k = 0; k < FSIZE; k++) {
			pair f = fire.front();
			fire.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = f.first + dx[dir];
				int ny = f.second + dy[dir];

				if (nx < 0 || ny < 0 || nx >= H || ny >= W)
					continue;
				//@가 있든 말든 불은 이동함
				if (mtrx[nx][ny] == '#' || mtrx[nx][ny] == '*')
					continue;
				fire.push({ nx,ny });
				mtrx[nx][ny] = '*';
				visited[nx][ny] = true;
			}
		}

		int MSIZE = man.size();
		answer++;
		for (int i = 0; i < MSIZE; i++) {
			pair p = man.front();
			man.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = p.first + dx[dir];
				int ny = p.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= H || ny >= W)
					continue;
				if (mtrx[nx][ny] == '#' || mtrx[nx][ny] == '*')
					continue;
				if (visited[nx][ny])
					continue;
				if (nx == 0 || ny == 0||nx==H-1||ny==W-1) {
					return true;
				}
				man.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	//[0][] or [][0]에 걸린게 없으니까 빌딩탈출실패
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> W >> H;

		queue<pair> fire;
		queue<pair> man;
		memset(visited, 0, sizeof(visited));
			
		for (int i = 0; i < H; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < W; j++) {
				mtrx[i][j] = tmp[j];
				if (tmp[j] == '*') {
					fire.push({ i,j });
					visited[i][j] = true;
				}
				else if (tmp[j] == '@') {
					man.push({ i,j });
					
				}
				else if (tmp[j] == '#')
					visited[i][j] = true;
			}
		}

		if (man.front().first == 0 || man.front().second == 0 || man.front().first == H - 1 || man.front().second == W - 1)
			cout << 1 << "\n";
		else if (func(fire,man))
			cout << answer+1 << "\n";
		else
			cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}