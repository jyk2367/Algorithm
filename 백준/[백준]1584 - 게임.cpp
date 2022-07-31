#include <iostream>
#include <queue>

#define SAFE 0
#define DANGER 1
#define DEATH 2


using namespace std;

int N,M;
int X1, Y1, X2, Y2;


int mtrx[502][502];
bool visited[502][502];

struct Node {
	int x;
	int y;
	int cost;
};

struct comp {
	bool operator()(const Node& n1, const Node& n2) {
		return n1.cost > n2.cost;
	}
};

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int bfs() {
	priority_queue<Node,vector<Node>,comp> pq;
	pq.push({ 0, 0 ,0});
	visited[0][0] = true;

	while (!pq.empty()) {
		int nowX= pq.top().x;
		int nowY= pq.top().y;
		int nowCost= pq.top().cost;

		pq.pop();

		if (nowX == 500 && nowY == 500) {
			return nowCost;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nextX = nowX + dx[dir];
			int nextY = nowY + dy[dir];

			if (nextX < 0 || nextY < 0 || nextX > 500 || nextY > 500)
				continue;
			if (visited[nextX][nextY])
				continue;
			visited[nextX][nextY] = true;

			if (mtrx[nextX][nextY] == SAFE) {
				pq.push({ nextX,nextY,nowCost });
			}
			else if (mtrx[nextX][nextY] == DANGER) {
				pq.push({ nextX,nextY,nowCost + 1 });
			}
		
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int k = 0; k < N; k++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		int i_min = min(X1, X2);
		int j_min = min(Y1, Y2);
		int i_max = max(X1, X2);
		int j_max = max(Y1, Y2);
		for (int i = i_min; i <=i_max; i++) {
			for (int j = j_min; j <=j_max; j++) {
				mtrx[i][j] = DANGER;
			}
		}
	}
	cin >> M;
	for (int k = 0; k < M; k++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		int i_min = min(X1, X2);
		int j_min = min(Y1, Y2);
		int i_max = max(X1, X2);
		int j_max = max(Y1, Y2);
		for (int i = i_min; i <=i_max; i++) {
			for (int j = j_min; j <=j_max; j++) {
				mtrx[i][j] = DEATH;
			}
		}
	}

	cout<<bfs()<<"\n";
	
	return 0;
}