#include <iostream>
#define BOARDSIZE 10

using namespace std;

int N;
int T, X, Y;
int answer;
int mtrx[BOARDSIZE][BOARDSIZE];

void OneToDown() {
	int i = 0;
	for (i = X + 1; i < BOARDSIZE; i++) {
		if (mtrx[i][Y] == 1)
			break;
	}

	mtrx[i - 1][Y] = 1;
}
void OneTwoToDown() {
	int i = 0;
	for (i = X + 1; i < BOARDSIZE; i++) {
		if (mtrx[i][Y] == 1 || mtrx[i][Y + 1] == 1)
			break;
	}

	mtrx[i - 1][Y] = 1;
	mtrx[i - 1][Y + 1] = 1;
}
void TwoOneToDown() {
	int i = 0;
	for (i = X + 2; i < BOARDSIZE; i++) {
		if (mtrx[i][Y] == 1)
			break;
	}

	mtrx[i - 2][Y] = 1;
	mtrx[i - 1][Y] = 1;
}
void OneToRight() {
	int j = 0;
	for (j = Y + 1; j < BOARDSIZE; j++) {
		if (mtrx[X][j] == 1)
			break;
	}

	mtrx[X][j - 1] = 1;
}
void OneTwoToRight() {
	int j = 0;
	for (j = Y + 2; j < BOARDSIZE; j++) {
		if (mtrx[X][j] == 1)
			break;
	}

	mtrx[X][j - 2] = 1;
	mtrx[X][j - 1] = 1;
}
void TwoOneToRight() {
	int j = 0;
	for (j = Y + 1; j < BOARDSIZE; j++) {
		if (mtrx[X][j] == 1 || mtrx[X + 1][j] == 1)
			break;
	}

	mtrx[X][j - 1] = 1;
	mtrx[X + 1][j - 1] = 1;
}
void MoveToBlue() {
	switch (T) {
	case 1://한칸짜리 아래로
		OneToRight();
		break;
	case 2://가로짜리 아래로
		OneTwoToRight();
		break;
	case 3://세로짜리 아래로
		TwoOneToRight();
		break;
	}
}
void MoveToGreen() {
	switch (T) {
	case 1://한칸짜리 아래로
		OneToDown();
		break;
	case 2://가로짜리 아래로
		OneTwoToDown();
		break;
	case 3://세로짜리 아래로
		TwoOneToDown();
		break;
	}
}

// 행을 지워도 되는가?
bool isRowRemovable(int row) {
	for (int j = 0; j < 4; j++) {
		if (mtrx[row][j] == 0)
			return false;
	}
	return true;
}

// 행 초기화
void InitRow(int row) {
	for (int j = 0; j < 4; j++) {
		mtrx[row][j] = 0;
	}
}

// 열을 지워도 되는가?
bool isColRemovable(int col) {
	for (int i = 0; i < 4; i++) {
		if (mtrx[i][col] == 0)
			return false;
	}
	return true;
}

// 열 초기화
void InitCol(int col) {
	for (int j = 0; j < 4; j++) {
		mtrx[j][col] = 0;
	}
}

// 행 이동
void MoveUpperRow(int row) {
	for (int i = row; i > 4; i--) {
		for (int j = 0; j < 4; j++) {
			mtrx[i][j] = mtrx[i-1][j];
		}
	}

	for (int j = 0; j < 4; j++) {
		mtrx[4][j] = 0;
	}
}

// 열 이동
void MoveLeftCol(int col) {
	for (int j = col; j > 4; j--) {
		for (int i = 0; i < 4; i++) {
			mtrx[i][j] = mtrx[i][j-1];
		}
	}

	for (int i = 0; i < 4; i++) {
		mtrx[i][4] = 0;
	}
}

// 재귀적으로 행 제거
void RcsvRemoveGreen(int rmvRow) {
	for (int i = rmvRow; i >= 6; i--) {
		if (isRowRemovable(i)) {
			InitRow(i);
			MoveUpperRow(i);
			RcsvRemoveGreen(i);
			answer++;
			break;
		}
	}
}

// 재귀적으로 열 제거
void RcsvRemoveBlue(int rmvCol) {
	for (int j = rmvCol; j >= 6; j--) {
		if (isColRemovable(j)) {
			InitCol(j);
			MoveLeftCol(j);
			RcsvRemoveBlue(j);
			answer++;
			break;
		}
	}
}

// 아래로 밀기
void MoveDown() {
	for (int i = BOARDSIZE-1; i > 4; i--) {
		for (int j = 0; j < 4; j++) {
			mtrx[i][j] = mtrx[i-1][j];
		}
	}

	for (int j = 0; j < 4; j++) {
		mtrx[4][j] = 0;
	}
}

void MoveRight() {
	for (int j = BOARDSIZE - 1; j > 4; j--) {
		for (int i = 0; i < 4; i++) {
			mtrx[i][j] = mtrx[i][j-1];
		}
	}

	for (int i = 0; i < 4; i++) {
		mtrx[i][4] = 0;
	}
}

int WeakGreenRowCnt() {
	int cnt = 0;
	for (int i = 4; i <= 5; i++) {
		bool state = true;
		for (int j = 0; j < 4; j++) {
			if (mtrx[i][j] == 1) {
				state = false;
				break;
			}
		}
		if (!state)
			cnt++;
	}
	return cnt;
}

int WeakBlueColCnt() {
	int cnt = 0;
	for (int j = 4; j <= 5; j++) {
		bool state = true;
		for (int i = 0; i < 4; i++) {
			if (mtrx[i][j] == 1) {
				state = false;
				break;
			}
		}
		if (!state)
			cnt++;
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--) {
		cin >> T >> X >> Y;
		
		// 파, 녹 보드로 이동
		MoveToGreen();
		MoveToBlue();
		
		

		// 녹색 보드 행, 파란색 보드 열 제거작업 시작(이게 점수, 제거된 행, 열 숫자만큼 제거된 행 위쪽애들 아래로 shift , 열 왼쪽애들 아래로  shift)
		RcsvRemoveGreen(BOARDSIZE - 1);
		RcsvRemoveBlue(BOARDSIZE - 1);

		

		// 만약 연한 칸에 블록이 있는 경우가 있다면, 맨 벽면에서 위쪽,왼쪽 전부 shift
		int weakRowSize = WeakGreenRowCnt();
		int weakColSize = WeakBlueColCnt();

		for (int i = 0; i < weakRowSize; i++) {
			MoveDown();
		}
		for (int i = 0; i < weakColSize; i++) {
			MoveRight();
		}

		
	}

	int GreenCnt = 0;
	for (int i = 4; i < BOARDSIZE; i++) {
		for (int j = 0; j < 4; j++) {
			if(mtrx[i][j]==1)
				GreenCnt++;
		}
	}

	int BlueCnt = 0;
	for (int j = 4; j < BOARDSIZE; j++) {
		for (int i = 0; i < 4; i++) {
			if (mtrx[i][j] == 1)
				BlueCnt++;
		}
	}

	cout << answer << "\n";
	cout << BlueCnt + GreenCnt<<"\n";




	return 0;
}