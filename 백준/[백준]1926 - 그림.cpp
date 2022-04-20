#include <iostream>
#include <string>
#include <queue>

using namespace std;

int ** paint;
bool ** visited;
//상하좌우
int dir_x[] = {0,0,-1,1};
int dir_y[] = {-1,1,0,0};


int bfs(int now_x, int now_y,int N,int M) {
	int cnt = 0;
	visited[now_x][now_y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(now_x, now_y));

	while (!q.empty()) {
		cnt++;
		pair<int,int> p=q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dir_x[i];
			int next_y = p.second + dir_y[i];
			
			if (next_x < 0 || next_x >= N||next_y<0||next_y>=M)
				continue;
			if (visited[next_x][next_y] == true||paint[next_x][next_y]==0)
				continue;
			q.push(make_pair(next_x, next_y));
			visited[next_x][next_y] = true;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N=0,M=0;
	int tmp=0;
	int cnt = 0;
	int area = 0;
	cin >> N >> M;

	paint = new int*[N];
	visited = new bool*[N];
	for (int i = 0; i < N; i++) {
		paint[i]=new int[M];
		visited[i] = new bool[M];
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			paint[i][j] = tmp;
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (paint[i][j]==1&&visited[i][j]==false) {
				tmp = bfs(i,j,N,M);
				if (tmp > area)
					area = tmp;
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	if (cnt != 0)
		cout << area << "\n";
	else
		cout << 0 << "\n";
}