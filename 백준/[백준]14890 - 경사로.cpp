#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Area {
	int height;
	int dist;
	int index;
};

int N,L;
int MAP[102][102];
int selected[102][102];
vector<Area> row[102];
vector<Area> col[102];
int roadCnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		int num = MAP[i][0];
		int cnt = 1;
		int index = 0;
		for (int j = 1; j < N; j++) {
			if (num == MAP[i][j]) {
				cnt++;
			}
			else {
				row[i].push_back({ num,cnt,index });
				num = MAP[i][j];
				cnt = 1;
				index = j;
			}
		}
		row[i].push_back({ num,cnt,index });
	}

	for (int j = 0; j < N; j++) {
		int num = MAP[0][j];
		int cnt = 1;
		int index = 0;
		for (int i = 1; i < N; i++) {
			if (num == MAP[i][j]) {
				cnt++;
			}
			else {
				col[j].push_back({ num,cnt,index });
				num = MAP[i][j];
				cnt = 1;
				index = i;
			}
		}
		col[j].push_back({ num,cnt,index });
	}

	for (int i = 0; i < N; i++) {
		if (row[i].size() == 1) {
			roadCnt++;
			continue;
		}

		bool cross = true;
		for (int j = 0; j < row[i].size()-1; j++) {
			Area & p1 = row[i][j];
			Area & p2 = row[i][j + 1];

			// 높이차가 1이 아니면 안됨
			if (abs(p1.height - p2.height) != 1) {
				cross = false;
				break;
			}

			// 높이 낮은곳 길이 < L이면 안됨
			if (p1.height<=p2.height){
				if (p1.dist < L) {
					cross = false;
					break;
				}

				//낮에서 높 : 높에서 아래로 L개
				bool isDuplicated = false;
				for (int k = p2.index - 1;k>=p2.index-L; k--) {
					if (selected[i][k]) {
						isDuplicated = true;
						break;
					}
					selected[i][k] = true;
				}

				if (isDuplicated) {
					cross = false;
					break;
				}
			}
			else if (p1.height > p2.height) {
				if (p2.dist < L) {
					cross = false;
					break;
				}

				//높에서 낮 : 낮 시작점에서 L개
				bool isDuplicated = false;
				for (int k = p2.index; k <p2.index+L; k++) {
					if (selected[i][k]) {
						isDuplicated = true;
						break;
					}
					selected[i][k] = true;
				}

				if (isDuplicated) {
					cross = false;
					break;
				}
			}
		}

		if (cross)
			roadCnt++;
	}

	//중복확인맵 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			selected[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		if (col[i].size() == 1) {
			roadCnt++;
			continue;
		}

		
		bool cross = true;
		for (int j = 0; j < col[i].size()-1; j++) {
			Area& p1 = col[i][j];
			Area& p2 = col[i][j + 1];
			// 높이차가 1이 아니면 안됨
			if (abs(p1.height - p2.height) != 1) {
				cross = false;
				break;
			}

			// 높이 낮은곳 길이 < L이면 안됨
			if (p1.height <= p2.height) {
				if (p1.dist < L) {
					cross = false;
					break;
				}

				//경사로 중복되면 안됨
				bool isDuplicated = false;
				for (int k = p2.index - 1; k >= p2.index - L; k--) {
					if (selected[k][i]) {
						isDuplicated = true;
						break;
					}
					selected[k][i] = true;
				}

				if (isDuplicated) {
					cross = false;
					break;
				}
			}
			else if (p1.height > p2.height) {
				if (p2.dist < L) {
					cross = false;
					break;
				}

				//경사로 중복되면 안됨
				bool isDuplicated = false;
				for (int k = p2.index; k < p2.index + L; k++) {
					if (selected[k][i]) {
						isDuplicated = true;
						break;
					}
					selected[k][i] = true;
				}

				if (isDuplicated) {
					cross = false;
					break;
				}
			}

		}


		if (cross)
			roadCnt++;
	}
	cout << roadCnt << "\n";

	return 0;
}
