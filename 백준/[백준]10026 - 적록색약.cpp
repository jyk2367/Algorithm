#include <bits/stdc++.h>
using namespace std;

char mtrx[102][102];
bool visited1[102][102];
bool visited2[102][102];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N;

void normal(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited1[x][y] = true;
	int stchar = mtrx[x][y];

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited1[nx][ny])
				continue;
			if (mtrx[nx][ny]!= stchar)
				continue;
			q.push({ nx,ny });
			visited1[nx][ny]=true;
		}

	}
}
void RGSAME(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited2[x][y] = true;
	int stchar = mtrx[x][y];

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited2[nx][ny])
				continue;
			if ((stchar == 'R' || stchar == 'G') && (mtrx[nx][ny] == 'R' || mtrx[nx][ny] == 'G')) {
				q.push({ nx,ny });
				visited2[nx][ny] = true;
			}
			else if (mtrx[nx][ny] == stchar) {
				q.push({ nx,ny });
				visited2[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			mtrx[i][j] = tmp[j];
		}
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited1[i][j]) {
				normal(i, j);
				cnt1++;
			}
			if (!visited2[i][j]) {
				RGSAME(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;

	return 0;
}