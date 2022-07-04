#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int N;
int board[102][102];
long long dp[102][102];

//오,아래
const int dx[] = {0,1};
const int dy[] = {1,0};

long long dfs(int x,int y) {
	if (x == N - 1 && y == N - 1)
		return 1;
	if (x < 0 || y < 0 || x >= N || y >= N)
		return 0;
	if (board[x][y] == 0)
		return 0;
	if (dp[x][y] != 0)
		return dp[x][y];


	dp[x][y] += dfs(x + dx[0] * board[x][y], y + dy[0] * board[x][y]);
	dp[x][y] += dfs(x + dx[1] * board[x][y], y + dy[1] * board[x][y]);
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	cout << dfs(0, 0) <<"\n";

	return 0;
}