#include <bits/stdc++.h>
using namespace std;

bool visited[102][102];
int matrix[102][102];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int N;
int answer=0x7fffffff;

vector<pair<int, int>> land;

int bfs(int color) {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == color) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	int dist = 0;

	while (!q.empty()) {
		int QSIZE = q.size();
		for(int i=0;i<QSIZE;i++){
			pair<int,int> p=q.front();
			q.pop();
			
			for (int dir = 0; dir < 4; dir++) {
				int nextX = p.first + dx[dir];
				int nextY = p.second + dy[dir];
				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
					continue;
				if (visited[nextX][nextY])
					continue;
				if (matrix[nextX][nextY]!= 0 &&matrix[nextX][nextY] != color)
					return dist;
				if (matrix[nextX][nextY] == 0) {
					q.push({ nextX,nextY });
					visited[nextX][nextY] = true;
				}
			}
		}
		dist++;
	}
}



void dfs(int x,int y,int color) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	matrix[x][y] = color;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int nextX = p.first + dx[i];
			int nextY = p.second + dy[i];

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
				continue;
			if (visited[nextX][nextY])
				continue;
			if (matrix[nextX][nextY] == 0)
				continue;
			q.push({ nextX,nextY });
			visited[nextX][nextY] = true;
			matrix[nextX][nextY] = color;
		}
	}

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1)
				land.push_back({ i,j });
		}
	}
	int color = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]&&matrix[i][j]==1) {
				dfs(i, j, color);
				color++;
			}
		}
	}

	for (int i = 1; i < color; i++) {
		memset(visited, 0, sizeof(visited));
		answer = min(bfs(i), answer);
	}

	cout << answer << "\n";

	
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// bool visited[102][102];
// int matrix[102][102];

// int dx[] = { 0,0,1,-1 };
// int dy[] = { 1,-1,0,0 };

// int N;
// int answer=0x7fffffff;

// vector<pair<int, int>> land;


// void dfs(int x,int y,int color) {
// 	queue<pair<int, int>> q;
// 	q.push({ x,y });
// 	visited[x][y] = true;
// 	matrix[x][y] = color;
// 	while (!q.empty()) {
// 		pair<int, int> p = q.front();
// 		q.pop();
		

// 		for (int i = 0; i < 4; i++) {
// 			int nextX = p.first + dx[i];
// 			int nextY = p.second + dy[i];

// 			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
// 				continue;
// 			if (visited[nextX][nextY])
// 				continue;
// 			if (matrix[nextX][nextY] == 0)
// 				continue;
// 			q.push({ nextX,nextY });
// 			visited[nextX][nextY] = true;
// 			matrix[nextX][nextY] = color;
// 		}
// 	}

// }



// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);


// 	cin >> N;

// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			cin >> matrix[i][j];
// 			if (matrix[i][j] == 1)
// 				land.push_back({ i,j });
// 		}
// 	}
// 	int color = 1;
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			if (!visited[i][j]&&matrix[i][j]==1) {
// 				dfs(i, j, color);
// 				color++;
// 			}
// 		}
// 	}
// 	int LSIZE = land.size();
// 	for (int i = 0; i < LSIZE-1; i++) {
// 		pair<int, int> p1 = land[i];
// 		int x1 = p1.first;
// 		int y1 = p1.second;
// 		for (int j = 1; j < LSIZE; j++) {
// 			if (i == j)
// 				continue;
// 			pair<int, int> p2 = land[j];
// 			int x2 = p2.first;
// 			int y2 = p2.second;
// 			if (matrix[x1][y1] == matrix[x2][y2])
// 				continue;
// 			answer = min(abs(x1 - x2) + abs(y1 - y2) - 1, answer);
// 		}
// 	}


// 	cout << answer << "\n";

	
// 	return 0;
// }