#include <bits/stdc++.h>
#define threepair pair<int,pair<int,int>> 
using namespace std;

int R,C,H;
int mtrx[102][102][102];
bool visited[102][102][102];

int dz[] = { 0,0,0,0,-1,1 };
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};

int func(queue<threepair> &riped) {

	int answer = 0;

	while (!riped.empty()) {
		int ripedsize = riped.size();
		answer++;
		for (int i = 0; i < ripedsize; i++) {
			threepair p = riped.front();
			riped.pop();
			int nowZ = p.first;
			int nowX = p.second.first;
			int nowY = p.second.second;
			for (int dir = 0; dir < 6; dir++) {
				int nextX = nowX + dx[dir];
				int nextY = nowY + dy[dir];
				int nextZ = nowZ + dz[dir];

				if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C || nextZ < 0 || nextZ >= H)
					continue;
				if (visited[nextZ][nextX][nextY])
					continue;
				if (mtrx[nextZ][nextX][nextY] !=0)
					continue;
				riped.push({ nextZ,{nextX,nextY} });
				visited[nextZ][nextX][nextY] = true;
			}
		}
	}
	return answer-1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> C>>R>>H;
	queue<threepair> riped;
	int check = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> mtrx[k][i][j];
				if (mtrx[k][i][j] == 1) {
					visited[k][i][j] = true;
					riped.push({ k,{i,j} });
				}
				else if (mtrx[k][i][j] == 0)
					check++;
				else
					visited[k][i][j] = true;

			}
		}
	}

	if (check == 0) {
		cout << 0 << "\n";
		return 0;
	}
	
	int day = func(riped);
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (visited[k][i][j] == false) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << day << "\n";

	return 0;
}