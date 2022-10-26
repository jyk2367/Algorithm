#include <iostream>
#include <algorithm>

#define MAX 4

using namespace std;


struct FISH {
	int x;
	int y;
	int dir;
	bool Live;
};

//물고기별 정보
FISH fish[17];

//물고기 점수
int board[MAX][MAX];

// 북	서북		서	서남		남	동남		동	동북
// 0	1		2	3		4	5		6	7
const int dx[] = { -1,-1,0,1,1,1,0,-1 };
const int dy[] = { 0,-1,-1,-1,0,1,1,1 };

int answer;

void moveFish() {
	// 1~16 물고기 순서대로 이동
	for (int i = 1; i <= 16; i++) {
		if (fish[i].Live == false)
			continue;

		int x = fish[i].x;
		int y = fish[i].y;
		int nowDir = fish[i].dir;

		for (int dir = 0; dir < 8; dir++) {
			int nextDir = (nowDir + dir) % 8;
			int nx = x + dx[nextDir];
			int ny = y + dy[nextDir];

			//이동하려는 칸이 경계를 벗어나면 skip
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue;

			//이동하려는 칸이 상어라면 skip
			if (board[nx][ny] == -1)
				continue;

			//이동하려는 칸이 비었다면
			if (board[nx][ny] == 0) {
				fish[i].x = nx;
				fish[i].y = ny;
				swap(board[x][y], board[nx][ny]);
			}
			//이동하려는 칸에 다른 물고기가 있다면
			else if (board[nx][ny] > 0) {
				swap(fish[i].x,fish[board[nx][ny]].x);
				swap(fish[i].y,fish[board[nx][ny]].y);
				swap(board[x][y], board[nx][ny]);
			}
			fish[i].dir = nextDir;
			break;
		}
	}
}

void BackUp(int a[][4],int b[][4],FISH c[],FISH d[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = b[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		c[i] = d[i];
	}
}

void func(int x,int y,int Dir,int Sum) {
	answer = max(Sum, answer);

	//0. 물고기 백업 
	int tmp_board[4][4]; 
	FISH tmp_fish[17];
	BackUp(tmp_board, board,tmp_fish,fish);
	
	
	//1. 물고기 옮기기
	moveFish();

	//2. 상어 옮기기
	for (int i = 1; i < 4; i++) {
		int nx = x + dx[Dir] * i;
		int ny = y + dy[Dir] * i;

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			continue;

		if (board[nx][ny] == 0)
			continue;

		int tmpFishNum = board[nx][ny];
		int tmpDir = fish[tmpFishNum].dir;


		board[x][y] = 0;	// 빈 곳으로 변경
		board[nx][ny] = -1; // 상어 있는곳으로 변경
		fish[tmpFishNum].Live = false;

		func(nx, ny, tmpDir, Sum + tmpFishNum);

		board[x][y] = -1;
		board[nx][ny] = tmpFishNum;
		fish[tmpFishNum].Live = true;

	}


	//3. 다시 원상복구
	BackUp(board, tmp_board, fish, tmp_fish);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// a : 번호, b : 방향
			int a, b;
			cin >> a >> b;
			board[i][j] = a;
			fish[a] = { i, j, b - 1 ,true };
		}
	}


	//(0,0) 물고기 잡아먹고 시작
	int tmpfishNum = board[0][0];
	int tmpDir = fish[tmpfishNum].dir;
	fish[tmpfishNum].Live = false;
	board[0][0] = -1;

	func(0,0, tmpDir, tmpfishNum);
	
	cout << answer;

	return 0;
}