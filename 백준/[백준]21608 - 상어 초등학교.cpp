#include <bits/stdc++.h>
using namespace std;
int N;

int mtrx[21][21];
int favorite[1000][4];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
//x,y,빈 칸수,좋아하는 학생칸수
bool comp(const pair<pair<int,int>,pair<int,int>> &p1, const pair<pair<int, int>, pair<int, int>>& p2) {
	//1. 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	//2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
	//3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.

	if (p1.second.second == p2.second.second) {
		if (p1.second.first == p2.second.first) {
			if (p1.first.first == p2.first.first) {
				return p1.first.second > p2.first.second;
			}
			return p1.first.first > p2.first.first;
		}
		else
			return p1.second.first < p2.second.first;
	}
	return p1.second.second < p2.second.second;

}

int main(void) {
	ios::sync_with_stdio(0);

	cin >> N;
	int Wcnt = N * N;
	while (Wcnt--) {
		int num;
		cin >> num;

		for (int i = 0; i < 4; i++) {
			cin >> favorite[num][i];
		}

		vector<pair<pair<int, int>, pair<int, int>>> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mtrx[i][j] == 0) {

					int emptyCnt = 0;
					int favCnt = 0;

					for (int dir = 0; dir < 4; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N)
							continue;

						if (mtrx[nx][ny] == 0) {
							emptyCnt++;
						}
						for (int k = 0; k < 4; k++) {
							if (mtrx[nx][ny] == favorite[num][k])
								favCnt++;
						}
					}

					v.push_back({{i,j}, { emptyCnt,favCnt }	});
				}
			}
		}

		if (!v.empty()) {

			sort(v.begin(), v.end(), comp);
			int x = v.back().first.first;
			int y = v.back().first.second;
			mtrx[x][y] = num;
			v.pop_back();
		}

	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int favCnt = 0;
			int num = mtrx[i][j];

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;

				for (int k = 0; k < 4; k++) {
					if (mtrx[nx][ny] == favorite[num][k])
						favCnt++;
				}
			}

			switch (favCnt) {
			case 0:
				sum += 0;
				break;
			case 1:
				sum += 1;
				break;
			case 2:
				sum += 10;
				break;
			case 3:
				sum += 100;
				break;
			case 4:
				sum += 1000;
				break;
			}

		}
	}

	cout << sum << "\n";


	return 0;
}