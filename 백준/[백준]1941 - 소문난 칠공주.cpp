#include <bits/stdc++.h>
#define PAIR pair<int,int>

using namespace std;

bool selected[5][5];
char mtrx[5][5];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int cnt = 0;

void bfs(vector<int>& v) {
	int p = 0;
	for (int i = 0; i < 7; i++) {
		if (mtrx[v[i] / 5][v[i] % 5] == 'S')
			p++;
	}
	if (p < 4)
		return;

	bool visited[5][5];
	for (int i = 0; i < 7; i++) {
		visited[v[i]/5][v[i]%5] = 0;
	}
	queue<PAIR> q;
	q.push({v[0] / 5, v[0] % 5});
	visited[v[0]/5][v[0]%5] = true;
	int connected = 0;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		connected++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = nowX + dx[dir];
			int ny = nowY + dy[dir];
			
			if (nx < 0 ||ny<0||nx>=5|| ny >= 5)
				continue;
			if (visited[nx][ny])
				continue;
			if (selected[nx][ny] == false)
				continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	if (connected == 7)
		cnt++;
}

void func(int k,int index,vector<int> &v) {
	if (k==7) {
		bfs(v);
		return;
	}

	for (int i = index; i < 25; i++) {
		if (v.empty() || v.back() < i) {
			v.push_back(i);
			selected[i/5][i%5] = true;
			func(k + 1, index + 1, v);
			selected[i/5][i%5] = false;
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 5; j++) {
			mtrx[i][j] = tmp[j];
		}
	}
	
	func(0,0,v);
	
	cout << cnt << "\n";

	return 0;
}
