#include <bits/stdc++.h>
using namespace std;
int N,M;
int mtrx[502][502];
int dp[502][502];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int dfs(int x,int y) {
	if (x == M - 1 && y == N - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if(mtrx[x][y]> mtrx[nx][ny])
			dp[x][y] += dfs(nx,ny);
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M>>N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i][j];
			dp[i][j] = -1;
		}
	}

	cout<<dfs(0, 0);


	return 0;
}