#include <bits/stdc++.h>
using namespace std;

int N,K;
int parent[100001];//부모 저장
bool visited[100001];

vector<int> func() {
	queue<pair<int,int>> q;
	q.push({ N,0 });
	visited[N] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int nowSec=q.front().second;
		q.pop();

		if (now == K) {
			int idx = now;
			vector<int> tmp;
			while (idx != N) {
				tmp.push_back(idx);
				idx = parent[idx];
			}
			tmp.push_back(idx);

			return tmp;
		}
		int next1 = now - 1;
		int next2 = now + 1;
		int next3 = now * 2;
		if (0 <= next1 && next1 <= 100000&&!visited[next1]) {
			parent[next1] = now;
			q.push({ next1,nowSec + 1 });
			visited[next1] = true;
		}
		if (0 <= next2 && next2 <= 100000 && !visited[next2]) {
			parent[next2] = now;
			q.push({ next2,nowSec + 1 });
			visited[next2] = true;
		}
		if (0 <= next3 && next3 <= 100000 && !visited[next3]) {
			parent[next3] = now;
			q.push({ next3,nowSec + 1 });
			visited[next3] = true;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	vector<int> answer = func();

	int ASIZE = answer.size();
	cout << ASIZE-1 << "\n";
	for (int i = ASIZE-1; i>=0; i--) {
		cout << answer[i] << " ";
	}
	return 0;
}