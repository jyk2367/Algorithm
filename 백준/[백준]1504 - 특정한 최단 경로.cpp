#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7fff'ffff

using namespace std;

int N, E;
int a, b, c;
int v1, v2;

struct Node {
	int dest;
	int dist;
};

vector<Node> al[802];
int dist[802];

int dijkstra(int start, int end) {
	for (int i = 0; i < 802; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int nowDist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (nowDist > dist[now])
			continue;

		if (now == end)
			return dist[end];

		for (Node node : al[now]) {
			int next = node.dest;
			int nextDist = node.dist;

			if (dist[next] > nowDist + nextDist) {
				dist[next] = nowDist + nextDist;
				pq.push({ dist[next], next });
			}
		}

	}

	return INF;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N>>E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		al[a].push_back({ b , c });
		al[b].push_back({ a , c });
	}
	cin >> v1 >> v2;

	int result = 0x7fff'ffff;
	int stv1 = dijkstra(1, v1);
	int v1v2 = dijkstra(v1, v2);
	int v2N = dijkstra(v2, N);
	if (stv1 != INF && v1v2 != INF && v2N != INF) {
		result = min(result, stv1 + v1v2 + v2N);
	}
	int stv2 = dijkstra(1, v2);
	int v2v1 = dijkstra(v2, v1);
	int v1N = dijkstra(v1, N);
	if (stv2 != INF && v2v1 != INF && v1N != INF) {
		result = min(result, stv2 + v2v1 + v1N);
	}
	
	if (result != INF)
		cout << result << "\n";
	else
		cout << -1 << "\n";

	
	return 0;
}