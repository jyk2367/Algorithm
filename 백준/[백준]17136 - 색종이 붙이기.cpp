#include <iostream>
#include <queue>

#define PaperRC 10

using namespace std;

//0 : 원본 값, 1 : 방문여부
int paper[PaperRC][PaperRC];
int colorPaperCnt[6] = { 0,5,5,5,5,5 };
int answer = 26;

bool checkColorPaper(int x, int y, int type) {
	for (int i = 0; i <type; i++) {
		for (int j = 0; j < type; j++) {
			if (x + i < 0 || y + j < 0 || x + i >= PaperRC || y + j >= PaperRC|| paper[x + i][y + j] == 0)
				return false;
		}
	}
	return true;
}

void switchingSelected(int x, int y, int type) {
	for (int i = 0; i < type; i++) {
		for (int j = 0; j < type; j++) {
			paper[x + i][y + j] ^= 1;
		}
	}
}

void func(int i,int j,int k) {
	if (i== PaperRC && j==0) {
		answer = min(k, answer);
		return;
	}

	
	int nextI = i + ((j + 1) / PaperRC);
	int nextJ = (j + 1) % PaperRC;

	if (paper[i][j] == 0) {
		func(nextI, nextJ, k);
	}
	else{
		for (int type =5; type>=1; type--) {
			if (checkColorPaper(i, j, type) && colorPaperCnt[type] > 0) {
				// 원본값이 1이면서 방문한적 없다고 하면 색종이를 씌울수 있는지 확인
				colorPaperCnt[type] -= 1;
				switchingSelected(i, j, type);
				func(nextI, nextJ, k + 1);
				switchingSelected(i, j, type);
				colorPaperCnt[type] += 1;

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