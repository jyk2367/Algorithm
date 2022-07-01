#include <bits/stdc++.h>
#include <unordered_set>

#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

using namespace std;

int R, C, M;

int mtrx[102][102];
int mtrx2[102][102];

const int dx[] = {0,-1,1,0,0};
const int dy[] = {0,0,0,1,-1};

struct Shark {
	int x;
	int y;
	int speed;
	int direction;
	int size;
};
Shark shark[10002];
int answer;

void changeDir(Shark& shark) {
	if (shark.direction == NORTH)
		shark.direction = SOUTH;
	else if (shark.direction == SOUTH)
		shark.direction = NORTH;
	else if (shark.direction == EAST)
		shark.direction = WEST;
	else if (shark.direction == WEST)
		shark.direction = EAST;
}

void moving(int x, int y, int si) {
	int cnt = 0;
	int nx = x;
	int ny = y;
	while (cnt < shark[si].speed) {
		nx += dx[shark[si].direction];
		ny += dy[shark[si].direction];

		if (nx<1 || nx>R || ny < 1 || ny > C) {
			changeDir(shark[si]);
			nx += dx[shark[si].direction] * 2;
			ny += dy[shark[si].direction] * 2;
		}

		cnt++;
	}

	if (mtrx2[nx][ny] != -1) {
		if(shark[mtrx2[nx][ny]].size < shark[si].size){
			mtrx2[nx][ny] = si;
		}
	}
	else {
		mtrx2[nx][ny] = si;
	}

}



void Init() {
	cin >> R >> C >> M;
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			mtrx[i][j] = -1;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> shark[i].x >> shark[i].y >> shark[i].speed >> shark[i].direction >> shark[i].size;
		mtrx[shark[i].x][shark[i].y] = i;
		if (shark[i].direction == NORTH || shark[i].direction == SOUTH)
			shark[i].speed%=((R-1)*2);
		if (shark[i].direction == EAST || shark[i].direction == WEST)
			shark[i].speed %= ((C - 1) * 2);;
	}
}

void getShark(int index) {
	for (int i = 1; i <= R; i++) {
		if (mtrx[i][index] != -1) {
			answer += shark[mtrx[i][index]].size;
			mtrx[i][index] = -1;
			break;
		}
	}
}
void moveShark() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			mtrx2[i][j] = -1;
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (mtrx[i][j] != -1) {
				moving(i,j, mtrx[i][j]);
				mtrx[i][j] = -1;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			mtrx[i][j]=mtrx2[i][j];
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Init();

	int king = 1;
	while (king <=C) {
		//현재 열에서 가장 가까운 상어잡기
		getShark(king);
		//모든 상어 이동
		moveShark();

		king++;
	}
	cout << answer << "\n";

	return 0;
}