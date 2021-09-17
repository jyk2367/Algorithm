#include <iostream>
#include <string>
#include <queue>

using namespace std;

int lot[] = {-1,1,2};
int dist[100002];
bool visited[100002] = { 0 };
void bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int next_n;
			if (lot[i] == 2) {
				next_n = 2 * num;
			}
			else {
				next_n = num + lot[i];
			}

			if (next_n >= 100001||next_n<0)
				continue;
			if (visited[next_n] == true)
				continue;
			if (next_n == k) {
				cout << dist[num];
				return;
			}
			q.push(next_n);
			visited[next_n] = true;
			dist[next_n]= dist[num] + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	fill(dist, dist + 100001, 1);
	if (N == K) {
		cout << 0;
		return 0;
	}
	bfs(N, K);

}