#include <iostream>
#include <queue>

#define PaperRC 10

using namespace std;

//0 : 원본 값, 1 : 방문여부
int paper[PaperRC][PaperRC];
bool selected[PaperRC][PaperRC];
int colorPaperCnt[6] = { 0,5,5,5,5,5 };
int answer = 26;

bool checkColorPaper(int x, int y, int type, vector<pair<int, int>>& selectedIJ) {
	for (int i = x; i < (x + type); i++) {
		for (int j = y; j < (y + type); j++) {
			if (i < 0 || j < 0 || i >= PaperRC || j >= PaperRC) {
				return false;
			}
			if (selected[i][j] == false && paper[i][j] == 1) {
				selected[i][j] = true;
				selectedIJ.push_back({ i,j });
			}
			else
				return false;
		}
	}

	return true;
}

void func(int i,int j,int k) {
	if (i== PaperRC && j==0) {
		answer = min(k, answer);
		return;
	}

	if (k > answer) {
		return;
	}
	
	int nextI = i + ((j + 1) / PaperRC);
	int nextJ = (j + 1) % PaperRC;

	if (paper[i][j] == 0 || selected[i][j] == true) {
		func(nextI, nextJ, k);
	}
	else{
		for (int type =5; type>=1; type--) {
			if (selected[i][j] == false && colorPaperCnt[type] > 0) {
				// 원본값이 1이면서 방문한적 없다고 하면 색종이를 씌울수 있는지 확인
				vector<pair<int, int>> selectedIJ;
				bool state = checkColorPaper(i, j, type, selectedIJ);
				if (state) {
					colorPaperCnt[type] -= 1;
					func(nextI, nextJ, k + 1);
					colorPaperCnt[type] += 1;
				}
				for (const pair<int, int>& p : selectedIJ) {
					selected[p.first][p.second] = false;
				}
				selectedIJ.clear();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < PaperRC; i++) {
		for (int j = 0; j < PaperRC; j++) {
			cin >> paper[i][j];
		}
	}
	
	// func()
	func(0,0,0);

	if (answer == 26) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}