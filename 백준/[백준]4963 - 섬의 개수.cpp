#include <bits/stdc++.h>
using namespace std;


int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

void func(int land[][52],bool visited[][52],int x,int y,int &W,int &H) {
	queue<pair<int,int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (visited[p.first][p.second])
			continue;
		visited[p.first][p.second] = true;


		for (int i = 0; i < 8; i++) {
			int nextx = p.first + dx[i];
			int nexty = p.second + dy[i];
			if (nextx < 0 || nexty < 0 || nextx >= H || nexty >= W)
				continue;
			if (visited[nextx][nexty])
				continue;
			if (land[nextx][nexty] == 0)
				continue;
			q.push({ nextx ,nexty });
		}

	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int W, H;
		cin >> W >> H;

		if (W == 0 && H == 0)
			break;

		bool visited[52][52];
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				visited[i][j] = false;
			}
		}

		int land[52][52];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> land[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (!visited[i][j]&&land[i][j]==1) {
					func(land,visited,i,j,W,H);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
	

	return 0;
}