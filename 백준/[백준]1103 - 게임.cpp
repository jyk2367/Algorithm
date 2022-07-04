#include <bits/stdc++.h>
#include <unordered_set>

#define Hole -1

using namespace std;

int N, M;
int board[52][52];
int dp[52][52];
bool visited[52][52];

int answer = -1;
bool cycle = false;

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M || board[x][y] == Hole) {
		return 0;
	}
	if (visited[x][y]) {
		cycle = true;
		return 0;
	}
	if (dp[x][y]!=0) {
		return dp[x][y];
	}

	int mv = board[x][y];
	visited[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir]* mv;
		int ny = y + dy[dir]* mv;

		dp[x][y] = max(dfs(nx, ny) + 1,dp[x][y]);
	}
	visited[x][y] = false;

	return  dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j]=='H') {
				board[i][j] = Hole;
			}
			else
				board[i][j] = tmp[j]-'0';
		}
	}


	int answer = dfs(0, 0);

	if (cycle)
		cout << -1 << "\n";
	else
		cout << answer << "\n";


	return 0;
}