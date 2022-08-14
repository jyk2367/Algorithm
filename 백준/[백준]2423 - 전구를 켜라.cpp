#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;

struct Node {
	int x;
	int y;
	int dist;

	Node(int X, int Y, int DST) :x(X), y(Y), dist(DST) {	}
};

vector<Node> al[502][502];
int dist[502][502];


struct comp {
	bool operator()(const Node& n1,const Node& n2) {
		return n1.dist > n2.dist;
	}
};


void dijkstra() {
	//꼭짓점 기준
	priority_queue<Node,vector<Node>,comp> pq;
	pq.push(Node{0,0,0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int nowX = pq.top().x;
		int nowY = pq.top().y;
		int nowDist = pq.top().dist;
		pq.pop();

		if (nowDist > dist[nowX][nowY])
			continue;

		for (auto next:al[nowX][nowY]) {
			if (dist[next.x][next.y] > nowDist + next.dist) {
				dist[next.x][next.y] = nowDist + next.dist;
				pq.push(Node{ next.x,next.y, dist[next.x][next.y] });
			}
			
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i <N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '\\') {
				al[i][j].push_back(Node{ i + 1,j + 1,0 });
				al[i + 1][j + 1].push_back(Node{ i,j ,0 });

				al[i + 1][j].push_back(Node{  i,j + 1  ,1});
				al[i][j + 1].push_back(Node{ i + 1,j  ,1});
			}
			else {
				al[i][j].push_back(Node{ i + 1,j + 1,1 });
				al[i + 1][j + 1].push_back(Node{ i,j ,1 });

				al[i + 1][j].push_back(Node{  i,j + 1  ,0 });
				al[i][j + 1].push_back(Node{  i + 1,j ,0 });
			}
		}
	}

	memset(dist, 0x3f, sizeof dist);
	dijkstra();
	if (dist[N][M] == 0x3f3f'3f3f) {
		cout << "NO SOLUTION\n";
	}
	else {
		cout << dist[N][M] << "\n";
	}

	return 0;
}