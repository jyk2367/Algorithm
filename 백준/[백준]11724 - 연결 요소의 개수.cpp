#include <bits/stdc++.h>
using namespace std;

bool visited[1002];

void func(int x,vector<int> v[1002]) {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int now = q.front();
		q.pop();


		int nowVsize = v[now].size();
		for (int i = 0; i < nowVsize; i++) {
			int next = v[now][i];
			if (visited[next])
				continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N>>M;
	vector<int> v[1002];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <=N; i++) {
		if (!visited[i]) {
			func(i,v);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}