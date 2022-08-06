#include <iostream>
#include <queue>

#define Threepair pair<pair<int,int>,int>
#define WALL 1
#define EMPTY 0

using namespace std;

int N, M;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int maze[102][102];

bool visited[102][102];

struct comp {
	bool operator()(const Threepair& p1,const Threepair&p2) {
		return p1.second > p2.second;
	}
};

int bfs() {
	priority_queue<Threepair,vector<Threepair>,comp> pq;
	pq.push({ {1,1},0 });
	visited[1][1] = true;
	while (!pq.empty()) {
		int nowX = pq.top().first.first;
		int nowY = pq.top().first.second;
		int nowCount = pq.top().second;
		pq.pop();

		if (nowX == N && nowY == M) {
			return nowCount;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nextX = nowX + dx[dir];
			int nextY = nowY + dy[dir];
			if (nextX<1 || nextY<1 || nextX>N || nextY>M)
				continue;
			if (visited[nextX][nextY])
				continue;
			visited[nextX][nextY] = true;
			if (maze[nextX][nextY] == WALL) {
				pq.push({ {nextX,nextY} ,nowCount + 1 });
			}
			else {
				pq.push({ {nextX,nextY} ,nowCount});
			}
		}

	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 1; i <=N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j <M; j++) {
			maze[i][j+1] = input[j]-'0';
		}
	}

	cout<<bfs();

	return 0;
}