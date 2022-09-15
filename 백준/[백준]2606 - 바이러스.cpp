#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> al[102];
bool visited[102];
int N, M;
int a, b;

int dijkstra() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int cnt = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : al[now]) {
			if (visited[next])
				continue;
			visited[next] = true;
			q.push(next);
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	cout<<dijkstra();

	
	return 0;
}