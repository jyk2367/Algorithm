#include <iostream>
#include <string>
#include <queue>

using namespace std;

int** matrix;
bool** visited;
//상하좌우
int dir_x[] = {0,0,-1,1};
int dir_y[] = {-1,1,0,0};

void bfs(int now_x,int now_y,int N,int M) {
	visited[now_x][now_y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(now_x, now_y));

	while (!q.empty()) {
		pair<int, int> p=q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dir_x[i];
			int next_y = p.second + dir_y[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;
			if (visited[next_x][next_y] == true || matrix[next_x][next_y] == 0)
				continue;
			q.push(make_pair(next_x, next_y));
			visited[next_x][next_y] = true;
			matrix[next_x][next_y] +=matrix[p.first][p.second];
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	matrix = new int* [N];
	visited = new bool* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M];
		visited[i] = new bool[M];
	}

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s.length() != M)
			return 0;
		for (int j = 0; j < M; j++) {
			matrix[i][j] = s[j]-'0';
			visited[i][j] = false;
		}
	}

	bfs(0, 0,N,M);
	
	cout << matrix[N - 1][M - 1] << "\n";
}