#include <bits/stdc++.h>
using namespace std;

int matrix[26][26];
bool visited[26][26];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int N;

int func(int x,int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int cnt = 0;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		cnt++;
		
		for (int i = 0; i < 4; i++) {
			int nextX = p.first + dx[i];
			int nextY = p.second + dy[i];

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
				continue;
			if (visited[nextX][nextY])
				continue;
			if (matrix[nextX][nextY] == 0)
				continue;
			visited[nextX][nextY] = true;
			q.push({ nextX, nextY });
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			matrix[i][j] = s[j] - '0';
		}
	}

	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && matrix[i][j] == 1) {
				cnt++;
				v.push_back(func(i, j));
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}