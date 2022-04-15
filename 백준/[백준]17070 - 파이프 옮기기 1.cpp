#include <bits/stdc++.h>
#define WALL 1
#define EMPTY 0

#define WIDTH 0
#define HEIGHT 1
#define DIAGONAL 2

using namespace std;
int N;
int mtrx[17][17];
int answer;
pair<pair<int, int>,int> pipe;

void func() {
	if (pipe.first.first > N || pipe.first.second > N) {
		return;
	}

	if ((pipe.first.first+1 == N && pipe.first.second+1 == N&&pipe.second==DIAGONAL)|| (pipe.first.first + 1 == N && pipe.first.second == N&&pipe.second==HEIGHT)|| (pipe.first.first== N && pipe.first.second + 1 == N&&pipe.second==WIDTH)) {
		answer++;
		//cout << pipe.first.first << " " << pipe.first.second << " " << pipe.second << "\n";
		return;
	}

	pair<pair<int,int>,int> origin = pipe;
	switch (pipe.second) {
	case WIDTH:	
		if (mtrx[pipe.first.first][pipe.first.second + 2] == 0) {
			pipe = { {pipe.first.first,pipe.first.second+1},WIDTH };
			func();
			pipe = origin;
		}
		if ((mtrx[pipe.first.first][pipe.first.second + 2] == 0) && (mtrx[pipe.first.first + 1][pipe.first.second + 1] == 0) && (mtrx[pipe.first.first + 1][pipe.first.second + 2] == 0)) {
			pipe = { {pipe.first.first,pipe.first.second + 1},DIAGONAL };
			func();
			pipe = origin;
		}
		break;
	case HEIGHT:
		if (mtrx[pipe.first.first+2][pipe.first.second] == 0) {
			pipe = { {pipe.first.first+1,pipe.first.second},HEIGHT };
			func();
			pipe = origin;
		}
		if ((mtrx[pipe.first.first+2][pipe.first.second] == 0) && (mtrx[pipe.first.first+1][pipe.first.second + 1] == 0) && (mtrx[pipe.first.first + 2][pipe.first.second + 1] == 0)) {
			pipe = { {pipe.first.first+1,pipe.first.second},DIAGONAL };
			func();
			pipe = origin;
		}
		break;
	case DIAGONAL:
		if (mtrx[pipe.first.first + 1][pipe.first.second + 2] == 0) {
			pipe = { {pipe.first.first + 1,pipe.first.second+1},WIDTH };
			func();
			pipe = origin;
		}
		if (mtrx[pipe.first.first + 2][pipe.first.second + 1] == 0) {
			pipe = { {pipe.first.first + 1,pipe.first.second+1},HEIGHT };
			func();
			pipe = origin;
		}
		if ((mtrx[pipe.first.first + 2][pipe.first.second + 1] == 0) && (mtrx[pipe.first.first + 1][pipe.first.second + 2] == 0) && (mtrx[pipe.first.first + 2][pipe.first.second + 2] == 0)) {
			pipe = { {pipe.first.first + 1,pipe.first.second + 1},DIAGONAL };
			func();
			pipe = origin;
		}
		break;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
		
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			cin >> mtrx[i][j];
		}
	}
	pipe = { {1,1} , WIDTH };

	func();

	cout << answer << "\n";
	


	return 0;
}