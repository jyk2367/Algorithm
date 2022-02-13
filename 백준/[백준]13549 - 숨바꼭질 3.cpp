#include <bits/stdc++.h>
using namespace std;
int answer;
bool visited[100001][3];

void bfs(int N, int K) {
	deque<pair<int, int>> dq;
	dq.push_front({N, 0});
	while (!dq.empty()) {
		int DQSIZE = dq.size();
		for (int i = 0; i < DQSIZE; i++) {
			int now = dq.front().first;
			int sec = dq.front().second;
			dq.pop_front();
			if (now == K) {
				answer = sec;
				return;
			}

			int next1 = now + 1;
			int next2 = now - 1;
			int next3 = now * 2;

			if (0 <= next1 && next1 <= 100000 && !visited[next1][0]) {
				dq.push_back({ next1,sec + 1 });
				visited[next1][0] = true;
			}
			if (0 <= next2 && next2 <= 100000 && !visited[next2][1]) {
				dq.push_back({ next2,sec + 1 });
				visited[next2][1] = true;
			}
			if (0 <= next3 && next3 <= 100000 && !visited[next3][2]) {
				dq.push_front({ next3,sec });
				visited[next3][2] = true;
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;

	bfs(N,K);
	cout << answer << "\n";
	
	return 0;
}