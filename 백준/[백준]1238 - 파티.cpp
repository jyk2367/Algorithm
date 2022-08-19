#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Road {
	int dest;
	int dist;
	Road() {
		dest = 0;
		dist = 0;
	};
	Road(int de, int di) :dest(de), dist(di) {	}
};

int N,M,X;
int a, b, t;
int dist[1002];

vector<Road> al[1002];

struct comp {
	bool operator ()(const Road& r1, const Road &r2) {
		return r1.dist > r2.dist;
	}
};

void dijkstra(int start,int end) {
	memset(dist, 0x3f, sizeof dist);

	priority_queue<Road,vector<Road>,comp> pq;
	pq.push(Road(start,0));

	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().dest;
		int nowDist = pq.top().dist;
		pq.pop();

		if (now == end) {
			dist[now] = min(dist[now], nowDist);
			return;
		}

		if (nowDist > dist[now])
			continue;

		for (Road nextRoad : al[now]) {
			int next = nextRoad.dest;
			int nextDist = nextRoad.dist;
			if (nextDist + nowDist < dist[next]) {
				dist[next] = nextDist + nowDist;
				pq.push(Road(next, dist[next]));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		al[a].push_back({ b,t });
	}

	
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		dijkstra(i,X);
		int d1 = dist[X];

		dijkstra(X,i);
		int d2 = dist[i];

		answer=max(d1+ d2,answer);
	}

	cout << answer << "\n";

	return 0;
}
​