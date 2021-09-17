#include <iostream>
#include <string>
#include <queue>
using namespace std;

//상하좌우
int dir_x[] = {0,0,-1,1};
int dir_y[] = {-1,1,0,0};

int **matrix;
bool** visited;
queue<pair<int, int>> stp;

void bfs(queue<pair<int,int>>stp,int M, int N) {
	queue<pair<int, int>> q;
	int STPSIZE = stp.size();
	for (int i = 0; i < STPSIZE;i++) {
		pair<int, int> stp_pr = stp.front();
		stp.pop();
		visited[stp_pr.first][stp_pr.second] = true;
		q.push(make_pair(stp_pr.first, stp_pr.second));
	}
	
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dir_x[i];
			int next_y = p.second + dir_y[i];
			if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
				continue;
			if (visited[next_x][next_y] == true || matrix[next_x][next_y] == -1 || matrix[next_x][next_y]>0)
				continue;
			q.push(make_pair(next_x, next_y));
			visited[next_x][next_y] = true;
			matrix[next_x][next_y] = matrix[p.first][p.second]+1;

		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M,num,tmp;
	int max=0;
	cin >> N >> M;
	matrix = new int* [M];
	visited = new bool* [M];
	
	for (int i = 0; i < M; i++) {
		matrix[i] = new int[N];
		visited[i] = new bool[N];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			matrix[i][j] = num;
			if (num == 1) {
				stp.push(make_pair(i, j));
			}
			visited[i][j] = false;
		}
	}
	
	bfs(stp, M,N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			else if (max < matrix[i][j]) {
				max = matrix[i][j];
			}
			
		}
		
	}
	
	cout << max-1 << "\n";

}
