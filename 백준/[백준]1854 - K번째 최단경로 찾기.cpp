#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int a, b, c;
struct N_T {
	int node;
	int cost;

	bool operator<(const N_T& nt)const {
		return this->cost > nt.cost;
	}
};

priority_queue<N_T> pq;
priority_queue<int> visited[1002];
vector<N_T> city[1002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n>>m>>k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
	}

	pq.push({ 1, 0 });
	visited[1].push(0);

	while (!pq.empty()) {
		N_T now = pq.top();
		pq.pop();

		for (N_T next : city[now.node]) {
			int ncost = now.cost + next.cost;
			if (visited[next.node].size() == k && ncost < visited[next.node].top()) {
				visited[next.node].pop();
			}
			if (visited[next.node].size() < k) {
				visited[next.node].push(ncost);
				pq.push({ next.node,ncost });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i].size() < k)
			cout << -1 << "\n";
		else
			cout << visited[i].top()<<"\n";
	}
	
	return 0;
}