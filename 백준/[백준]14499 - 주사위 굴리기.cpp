#include <bits/stdc++.h>
using namespace std;

int N, M,K;
int mtrx[22][22];
int dice[6];

//동서북남
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void moveDice(int dir);
void moving(int dir, int& x, int& y);

void moving(int dir,int &x,int &y) {
	int nx = x+dx[dir-1];
	int ny = y+dy[dir-1];

	if (nx < 0 || ny < 0 || nx >= N || ny >= M)
		return;

	moveDice(dir);
	if (mtrx[nx][ny] == 0) {//주사위 바닥면에 있는 수가 칸에 복사
		mtrx[nx][ny] = dice[5];
	}
	else {//칸에 있는 수를 주사위 바닥면으로 복사, 칸은 0
		dice[5] = mtrx[nx][ny];
		mtrx[nx][ny] = 0;
	}
	x = nx;
	y = ny;
	cout << dice[0] << "\n";
}

void moveDice(int dir) {
	if (dir == 1) {//동
		swap(dice[0], dice[3]);
		swap(dice[2], dice[3]);
		swap(dice[3], dice[5]);
	}
	else if (dir == 2) {//서
		swap(dice[0], dice[3]);
		swap(dice[0], dice[2]);
		swap(dice[2], dice[5]);
	}
	else if (dir == 3) {//북
		swap(dice[4], dice[5]);
		swap(dice[0], dice[1]);
		swap(dice[0], dice[5]);
	}
	else {
		swap(dice[4], dice[5]);
		swap(dice[0], dice[1]);
		swap(dice[1], dice[4]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> N >> M >> x>>y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
		}

	}
	int dir;
	while (K--) {
		cin >> dir;
		moving(dir,x,y);
	}
	

	return 0;
}