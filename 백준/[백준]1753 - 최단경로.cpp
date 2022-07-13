#include <iostream>
#include <vector>
#include <queue>
#define Pair pair<int,int>
#define INF 0x3f3f'3f3f
#define VERTEXSIZE 20002
using namespace std;

int V, E;
int a, b, c;
int sp;
vector<Pair> al[VERTEXSIZE];	//인접리스트
int dist[VERTEXSIZE];			//sp에서 각 정점까지의 거리

struct Comp {
	bool operator()(const Pair &p1, const Pair& p2) {
		if (p1.second == p2.second) {
			return p1.first > p2.first;
		}
		return p1.second > p2.second;
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	cin >> sp;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		al[a].push_back({ b,c });
	}

	//dist 배열 초기화
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[sp] = 0;

	//실제 노드 번호
	priority_queue<Pair,vector<Pair>, Comp> pq;
	pq.push({sp,0});

	while (!pq.empty()) {
		int now = pq.top().first;
		int nowDist = pq.top().second;
		pq.pop();

		for (Pair next : al[now]) {
			int nextV = next.first;
			int edgeCost = next.second;

			if (nowDist + edgeCost < dist[nextV]) {
				dist[nextV] = nowDist + edgeCost;
				pq.push({ nextV,dist[nextV] });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}