#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N;
int space[22][22];
bool visited[22][22];
pair<int, int> babyshark;
int babysharkSize = 2;
int babysharkEatCount = 0;
int T = 0;

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

bool comp(const pair<int, int>& p1, const pair<int, int>& p2){
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first<p2.first;
};

void Init() {
	T = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			if(space[i][j]> babysharkSize)
				visited[i][j] = true;
		}
	}
	space[babyshark.first][babyshark.second] = 0;
	visited[babyshark.first][babyshark.second] = true;
}

bool bfs() {
	Init();
	deque<pair<int, int>> dq;
	dq.push_back(babyshark);

	while (!dq.empty()) {
		int DQSIZE = dq.size();
		for (int i = 0; i < DQSIZE; i++) {
			int nowX= dq.front().first;
			int nowY = dq.front().second;
			dq.pop_front();

			//먹었으면 끝
			if (space[nowX][nowY] > 0 && space[nowX][nowY]< babysharkSize) {
				//이동
				space[nowX][nowY] = 9;
				babyshark = { nowX,nowY };

				babysharkEatCount++;
				if (babysharkEatCount == babysharkSize) {
					babysharkSize++;
					babysharkEatCount = 0;
				}
				return true;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = nowX + dx[dir];
				int ny = nowY + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (visited[nx][ny])
					continue;
				visited[nx][ny] = true;

				//크면 지나갈수도 없음
				if (space[nx][ny] > babysharkSize)
					continue;

				dq.push_back({ nx,ny });
				
			}
		}
		
		sort(dq.begin(), dq.end(), comp);
		
		T++;
	}

	return false;

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				babyshark = { i,j };
			}
		}
	}

	int answer = 0;
	while (true) {
		if (bfs()==false)
			break;
		answer += T;
	}
	cout << answer;



	return 0;
}
