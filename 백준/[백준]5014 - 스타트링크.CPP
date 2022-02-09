#include <bits/stdc++.h>
using namespace std;

int answer = 0x7fffffff;
bool visited[1000001];
int F, G, U, D;
void bfs(int now,int cnt) {
	
	queue<int> q;
	q.push(now);
	visited[now] = true;

	while (!q.empty()) {
		int QSIZE = q.size();
		cnt++;
		for (int i = 0; i < QSIZE; i++) {
			int now = q.front();
			q.pop();

			if (now == G) {
				answer = min(answer, cnt-1);
				return;
			}
			int nextUp = now + U;
			int nextDn = now - D;
			if (nextUp <= F&&!visited[nextUp]) {
				visited[nextUp] = true;
				q.push(nextUp);
			}
			if (nextDn >= 1&&!visited[nextDn]) {
				visited[nextDn] = true;
				q.push(nextDn);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int S;
	cin >> F >> S >> G >> U >> D;

	bfs(S,0);

	if (answer == 0x7fffffff)
		cout << "use the stairs";
	else
		cout << answer;

	return 0;
}