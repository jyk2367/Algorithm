#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, K;
int R, C;
int cnt;
int **board;


bool paste(int** sticker) {
	vector<pair<int, int>> v;
	for (int k = 0; k < R; k++) {
		for (int p = 0; p < C; p++) {
			if (sticker[k][p] == 1)
				v.push_back(make_pair(k, p));
		}
	}

	bool state=false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			vector<pair<int, int>> tmp;
			tmp.assign(v.begin(), v.end());

			state = true;
			while (!tmp.empty()) {
				pair<int, int> p = tmp.back();
				tmp.pop_back();
				int x = i + p.first;
				int y = j + p.second;
				if (x < 0 || x >= N || y < 0 || y >= M|| board[x][y] == 1) {
					state = false;
					break;
				}
			}
			if (state) {
				while (!v.empty()) {
					pair<int, int> p = v.back();
					v.pop_back();
					int x = i + p.first;
					int y = j + p.second;
					board[x][y] = 1;
				}
				return state;
			}

		}
	}
	return state;
}

int** rotate(int **sticker) {
	int col = R;
	int row = C;
	
	int** newSticker = new int*[row];
	for (int i = 0; i < row; i++) {
		newSticker[i] = new int[col];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			newSticker[j][R-1-i] = sticker[i][j];
		}
	}
	R = row;
	C = col;
	return newSticker;
}
//디버깅용
void printBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K;

	board = new int* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = 0;
		}
	}


	while (K--) {
		//sticker 선언
		cin >> R >> C;
		int** sticker = new int*[R];
		for (int i = 0; i < R; i++) {
			sticker[i] = new int[C];
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> sticker[i][j];
			}
		}

		//받은 sticker를 board에 붙이는데 rotate를 했는데 안된다면 return
		for (int i = 0; i < 4; i++) {
			if (paste(sticker)) {
				break;
			}
			int** newSticker = rotate(sticker);// 90도 회전
			sticker = newSticker;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1)
				cnt++;
		}
	}
	cout<<cnt;
}