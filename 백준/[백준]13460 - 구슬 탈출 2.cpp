#include <bits/stdc++.h>
#include <unordered_set>

#define EMPTY '.'
#define WALL '#'
#define HOLE 'O'
#define REDBEAD 'R'
#define BLUEBEAD 'B'

using namespace std;

int N, M;
char board[12][12];
pair<int, int> Hole, RedBead,BlueBead;
int answer = 0x7fff'ffff;

bool moveNorth() {
	bool state = false;
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			if (board[i][j] == WALL || board[i][j] == HOLE || board[i][j] == EMPTY)
				continue;
			if (board[i][j] == REDBEAD) {
				board[i][j] = EMPTY;
				int tmp = i;
				while (board[tmp-1][j] == EMPTY) {
					tmp--;
				}
				
				if (board[tmp - 1][j] == HOLE) {
					//구멍에 추가됨
					state=true;
					RedBead = { tmp-1,j };
				}
				else {
					board[tmp][j] = REDBEAD;
					RedBead = { tmp,j };
				}
			}
			if (board[i][j] == BLUEBEAD) {
				board[i][j] = EMPTY;
				int tmp = i;
				while (board[tmp - 1][j] == EMPTY) {
					tmp--;
				}

				if (board[tmp - 1][j] == HOLE) {
					//구멍에 추가됨
					BlueBead = { tmp-1,j };
				}
				else {
					board[tmp][j] = BLUEBEAD;
					BlueBead = { tmp,j };
				}
			}
		}
	}
	return state;
}

bool moveWest() {
	bool state = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == WALL || board[i][j] == HOLE || board[i][j] == EMPTY)
				continue;
			if (board[i][j] == REDBEAD) {
				board[i][j] = EMPTY;
				int tmp = j;
				while (board[i][tmp - 1] == EMPTY) {
					tmp--;
				}
				if (board[i][tmp - 1] == HOLE) {
					RedBead = { i,tmp-1 };
					state = true;
				}
				else {
					board[i][tmp] = REDBEAD;
					RedBead = { i,tmp };
				}
			}
			if (board[i][j] == BLUEBEAD) {
				board[i][j] = EMPTY;
				int tmp = j;
				while (board[i][tmp - 1] == EMPTY) {
					tmp--;
				}
				if (board[i][tmp - 1] == HOLE) {
					BlueBead = { i,tmp-1 };
				}
				else {
					board[i][tmp] = BLUEBEAD;
					BlueBead = { i,tmp };
				}
			}
		}
	}

	return state;
}
bool moveEast() {
	bool state = false;
	for (int i = 0; i < N; i++) {
		for (int j = M-1; j >=0; j--) {
			if (board[i][j] == WALL || board[i][j] == HOLE || board[i][j] == EMPTY)
				continue;
			if (board[i][j] == REDBEAD) {
				board[i][j] = EMPTY;
				int tmp = j;
				while (board[i][tmp + 1] == EMPTY) {
					tmp++;
				}
				
				if (board[i][tmp + 1] == HOLE) {
					//구멍에 추가됨
					RedBead = { i,tmp+1 };
					state = true;
				}
				else {
					board[i][tmp] = REDBEAD;
					RedBead = { i,tmp };
				}
			}
			if (board[i][j] == BLUEBEAD) {
				board[i][j] = EMPTY;
				int tmp = j;
				while (board[i][tmp + 1] == EMPTY) {
					tmp++;
				}

				if (board[i][tmp + 1] == HOLE) {
					BlueBead = { i,tmp+1 };
				}
				else {
					board[i][tmp] = BLUEBEAD;
					BlueBead = { i,tmp };
				}

			}

		}
	}



	return state;
}
bool moveSouth() {
	bool state = false;
	for (int j = 0; j < M; j++) {
		for (int i = N-1; i >=0; i--) {
			if (board[i][j] == WALL || board[i][j] == HOLE || board[i][j] == EMPTY)
				continue;
			if (board[i][j] == REDBEAD) {
				board[i][j] = EMPTY;
				int tmp = i;
				while (board[tmp + 1][j] == EMPTY) {
					tmp++;
				}

				if (board[tmp + 1][j] == HOLE) {
					//구멍에 추가됨
					RedBead = { tmp+1,j };
					state=true;
				}
				else {
					board[tmp][j] = REDBEAD;
					RedBead = { tmp,j };
				}
			}
			if (board[i][j] == BLUEBEAD) {
				board[i][j] = EMPTY;
				int tmp = i;
				while (board[tmp + 1][j] == EMPTY) {
					tmp++;
				}

				if (board[tmp + 1][j] == HOLE) {
					//구멍에 추가됨
					BlueBead = { tmp+1,j };
				}
				else {
					board[tmp][j] = BLUEBEAD;
					BlueBead = { tmp,j };
				}
			}
		}
	}
	return state;
}
//북 서 동 남
bool gravity(int dir) {
	bool state = false;
	if (dir == 0) {
		state=moveNorth();
	}
	else if (dir == 1) {
		state = moveWest();
	}
	else if (dir == 2) {
		state = moveEast();
	}
	else if (dir == 3) {
		state = moveSouth();
	}

	if (BlueBead.first == RedBead.first && BlueBead.second == RedBead.second)
		state = false;

	return state;
}

void func(int k,int last) {
	if (k >= 10) {
		return;
	}

	char backup[12][12];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			backup[i][j] = board[i][j];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		if (dir == last)//똑같은 값 연속 중복 제거
			continue;

		//gravity(구슬 위치 변경될수 있음)
		if (gravity(dir) == true) {
			answer = min(answer, k+1);
		}

		func(k + 1,dir);

		//원상복구
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board[i][j]= backup[i][j];
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			board[i][j]= tmp[j];
			if (tmp[j] == HOLE)
				Hole = { i,j };
			if (tmp[j] == REDBEAD)
				RedBead = { i,j };
			if (tmp[j] == BLUEBEAD)
				BlueBead = { i,j };
		}
	}

	func(0,-1);


 	if (answer == 0x7fff'ffff)
		cout << -1 << "\n";
	else
		cout << answer<<"\n";

	return 0;
}