#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>

#define Pair pair<int,int>

using namespace std;

char mtrx[52][52];
bool visited[52][52];
int hp[52][52];
int N;
int homeCount;
Pair post;

const int dx[] = { -1,0,0,1,-1,-1,1,1 };
const int dy[] = { 0,-1,1,0,-1,1,-1,1 };

set<int> st;

bool bfs(int left,int right) {
	if (left > hp[post.first][post.second] || hp[post.first][post.second] > right)
		return false;


	memset(visited, 0, sizeof visited);

	queue<Pair> q;
	q.push(post);
	visited[post.first][post.second] = true;
	int tmphomeCnt = homeCount;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		if (tmphomeCnt == 0) {
			return true;
		}

		for (int dir = 0; dir < 8; dir++) {
			int nx = nowX + dx[dir];
			int ny = nowY + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[nx][ny])
				continue;
			visited[nx][ny] = true;

			if (left <= hp[nx][ny] && hp[nx][ny] <= right) {
				if (mtrx[nx][ny] == 'K') {
					tmphomeCnt--;
				}
				q.push({ nx, ny });
			}
		}

	}

	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			mtrx[i][j] = tmp[j];
			if (tmp[j] == 'P') {
				post = { i,j };
			}
			if (tmp[j] == 'K') {
				homeCount++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> hp[i][j];
			st.insert(hp[i][j]);
		}
	}
	
	set<int>::iterator left = st.begin();
	set<int>::iterator right = st.begin();
	int answer = 0x7fff'ffff;
	while (left!=st.end()&&right != st.end()) {
		bool canVisit=bfs(*left,*right);

		if (canVisit) {
			answer = min( * right - *left,answer);
			left++;
		}
		else {
			right++;
		}
	}


	cout << answer << "\n";

	return 0;
}