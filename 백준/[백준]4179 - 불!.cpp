#include <iostream>
#include <string>
#include <queue>

using namespace std;

int** matrix1;
int** matrix2;
//상하좌우
int dir_x[] = {0,0,-1,1};
int dir_y[] = {-1,1,0,0};
void bfs(queue<pair<int, int>> p1,pair<int,int>p2, int R, int C) {
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	int PSIZE = p1.size();
	
	for (int i = 0; i < PSIZE; i++) {
		pair<int, int> p = p1.front();
		p1.pop();
		q1.push(make_pair(p.first, p.second));
	}
	q2.push(p2);

	while (!q1.empty()) {
		pair<int, int> p=q1.front();
		q1.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dir_x[i];
			int next_y = p.second + dir_y[i];
			
			if (next_x >= R || next_x < 0 || next_y >= C || next_y < 0)
				continue;
			if (matrix1[next_x][next_y]>=0|| matrix1[next_x][next_y]==-2)
				continue;
			q1.push(make_pair(next_x, next_y));
			matrix1[next_x][next_y]=matrix1[p.first][p.second]+1;
		}
	}
	while (!q2.empty()) {
		pair<int, int> p = q2.front();
		q2.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dir_x[i];
			int next_y = p.second + dir_y[i];

			if (next_x >= R || next_x < 0 || next_y >= C || next_y < 0) {
				cout << matrix2[p.first][p.second]+1;
				return;
			}
			if (matrix2[next_x][next_y]>=0 || matrix2[next_x][next_y] == -2)
				continue;
			if (matrix1[next_x][next_y] != -1 && matrix1[next_x][next_y] <= matrix2[p.first][p.second] + 1)
				continue;
			

			q2.push(make_pair(next_x, next_y));
			matrix2[next_x][next_y] = matrix2[p.first][p.second] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;
	
	matrix1 = new int* [R];
	matrix2 = new int* [R];

	pair<int, int>p2;
	queue<pair<int, int>> p1;

	for (int i = 0; i < R; i++) {
		matrix1[i] = new int[C];
		matrix2[i] = new int[C];
	}

	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		if (input.size() != C)
			return 0;
		for (int j = 0; j < C; j++) {
			if (input[j] == '#') {
				matrix1[i][j] = -2;
				matrix2[i][j] = -2;
			}
			else if (input[j] == 'F') {
				p1.push(make_pair(i, j));
				matrix1[i][j] = 0;
				matrix2[i][j] = -2;
			}
			else if (input[j] == 'J') {
				p2=make_pair(i, j);
				matrix1[i][j] = -2;
				matrix2[i][j] = 0;
			}
			else {
				matrix1[i][j] = -1;
				matrix2[i][j] = -1;
			}
		}
	}

	bfs(p1,p2,R, C);

}