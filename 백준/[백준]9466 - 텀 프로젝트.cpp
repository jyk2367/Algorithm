#include <bits/stdc++.h>
using namespace std;

map<int,int> matrix;
bool visited[100002];//방문
bool done[100002];//사이클 포함됨
int cnt;

void dfs(int now) {
	visited[now] = true;
	int next = matrix[now];

	if (!visited[next]) {
		dfs(next);//사이클까지 dfs
	}
	else {
		if (!done[next]) {
			//사이클에 왔으므로 cnt세기
			for (int i = next; i != now; i = matrix[i]) {
				cnt++;
			}
			cnt++;
		}
	}
	done[now] = true;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cin >> matrix[i];
			visited[i] = false;
			done[i] = false;
		}

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}

		cout << N-cnt << "\n";
		cnt = 0;
	}

	return 0;
}