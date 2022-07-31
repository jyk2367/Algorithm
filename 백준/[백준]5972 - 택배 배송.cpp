#include <iostream>
#include <vector>
#include <queue>

#define FARMSIZE 50'002
#define INF 0x3f3f'3f3f


using namespace std;

int N, M;
int a, b, c;

vector<pair<int,int>> al[FARMSIZE];
int dist[FARMSIZE];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({1,0});
	dist[1] = 0;
	
	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();

		if (dist[now] < nowCost)
			continue;

		for (pair<int, int> p : al[now]) {
			int next = p.first;
			int nextCost = p.second;

			if (nowCost + nextCost < dist[next]) {
				dist[next] = nowCost + nextCost;
				pq.push({next,dist[next]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		al[a].push_back({ b,c });
		al[b].push_back({ a,c });
	}

	for (int i = 1; i <=N; i++) {
		dist[i] = INF;
	}
	
	dijkstra();
	
	cout << dist[N] << "\n";

	return 0;
}