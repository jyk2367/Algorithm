#include <bits/stdc++.h>
using namespace std;

bool func(vector<int> graph[20002],int visited[20002],int sp) {
	queue<pair<int,vector<int>>> q;
	q.push({ 1,graph[sp] });
	visited[sp] = 1;

	while (!q.empty()) {
		pair<int,vector<int>> p = q.front();
		q.pop();
		int color = p.first==1?2:1;
		vector<int> v = p.second;


		for (int i = 0; i < v.size(); i++) {
			int next = v[i];
			if (visited[next]==p.first) {
				return false;
			}
			if (visited[next] > 0)//한번이라도 들어왔었으면 skip
				continue;
			visited[next] = color;
			q.push({ color,graph[next] });
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, V, E;
	cin >> K;
	while (K--) {
		cin >> V >> E;

		vector<int> graph[20002];
		int visited[20002];

		for (int i = 1; i <= V; i++) {
			visited[i] = 0;
		}

		//간선정보
		int u, v;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool answer = true;
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				if (!func(graph, visited, i)) {
					answer = false;
					break;
				}
			}
		}

		if (answer) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
		

	}

	
	return 0;
}