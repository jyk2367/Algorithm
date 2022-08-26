#include <iostream>
#include <vector>

#define INF 0X3f3f3f3f

using namespace std;

int TC,N,M,W;
int S, E, T;

struct Node {
	int start;
	int end;
	int dist;
};

vector<Node> Edge;
int dist[502];

bool bellmanford() {
	dist[1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < Edge.size(); j++) {
			int now = Edge[j].start;
			int next = Edge[j].end;
			int dst = Edge[j].dist;
			if (dist[now] + dst < dist[next]) {
				dist[next] = dist[now] + dst;
			}
		}
	}

	for (int j = 0; j < Edge.size(); j++) {
		int now = Edge[j].start;
		int next = Edge[j].end;
		int dst = Edge[j].dist;
		if (dist[now] + dst < dist[next]) {
			return true;
		}
	}

	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;

		//INIT
		Edge.clear();
		for (int i = 1; i <=N; i++) {
			dist[i] = INF;
		}

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			Edge.push_back({S,E,T});
			Edge.push_back({E,S,T});
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			Edge.push_back({ S,E,-T });
		}

		if (bellmanford()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}
	
	return 0;
}