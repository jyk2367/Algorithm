#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define  INF 0x3f3f'3f3f
#define VERTEXSIZE 1002

using namespace std;

int N, M;
int a, b, cost;
// 도착지 , 비용
vector<pair<int, int>>  al[VERTEXSIZE];
int dist[VERTEXSIZE];

struct comp {
	bool operator()(const pair<int, int>& p1,const pair<int,int>& p2) {
		if (p1.second==p2.second) {
			return p1.first > p2.first;
		}
		return p1.second > p2.second;
	}
};

long long dijkstra() {
	priority_queue<pair<int,int>,vector<pair<int,int>>, comp> pq;
	pq.push({ a , 0 });
	dist[a] = 0;

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
				pq.push({ next , dist[next] });
			}
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> cost;
		al[a].push_back({ b,cost });
	}

	for (int i = 1; i <=N; i++) {
		dist[i] = INF;
	}
	

	cin >> a >> b;
	dijkstra();
	cout << dist[b] << "\n";

	return 0;
}