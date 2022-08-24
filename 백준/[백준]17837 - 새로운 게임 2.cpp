#include <iostream>
#include <vector>

#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;

int N, K;

struct Horse{
	int index;
	int x;
	int y;
	int dir;
};

struct Chess {
	int color;
	vector<Horse*> horse;
};

Chess mtrx[14][14];
Horse h[12];


// 오 왼 상 하
const int dx[] = {0,0,0,-1,1};
const int dy[] = {0,1,-1,0,0};

int reverseDir(int dir) {
	switch (dir) {
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	}
}

int func() {

	int cnt = 0;
	while (cnt++<1000) {

		//순서대로 이동, 체스판 말 개수 4개 이상 쌓이면 종료
		for (int i = 1; i <= K; i++) {
			int nowIndex = h[i].index;
			int nowX = h[i].x;
			int nowY = h[i].y;
			int nowDir= h[i].dir;
			
			int nextX = nowX + dx[nowDir];
			int nextY = nowY + dy[nowDir];
			int nextDir = nowDir;

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N||mtrx[nextX][nextY].color==BLUE) {
				nextDir = reverseDir(nowDir);
				nextX = nowX + dx[nextDir];
				nextY = nowY + dy[nextDir];

				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N || mtrx[nextX][nextY].color == BLUE) {
					
				}
				else if (mtrx[nextX][nextY].color == WHITE) {
					//다음칸이 WHITE면 현재 index의 말 위에 있는 모든 말과 함께 next로 이동(방향 안바뀜, xy는 바뀜)
					for (int p = 0; p < mtrx[nowX][nowY].horse.size(); p++) {
						if (mtrx[nowX][nowY].horse[p] == &h[i]) {
							mtrx[nextX][nextY].horse.insert(mtrx[nextX][nextY].horse.end(), mtrx[nowX][nowY].horse.begin() + p, mtrx[nowX][nowY].horse.end());
							mtrx[nowX][nowY].horse.erase(mtrx[nowX][nowY].horse.begin() + p, mtrx[nowX][nowY].horse.end());
							break;
						}
					}

					for (Horse* horse : mtrx[nextX][nextY].horse) {
						(*horse).x = nextX;
						(*horse).y = nextY;
					}

					if (mtrx[nextX][nextY].horse.size() >= 4)
						return cnt;
				}
				else if(mtrx[nextX][nextY].color == RED) {
					while(!mtrx[nowX][nowY].horse.empty()) {
						mtrx[nextX][nextY].horse.push_back(mtrx[nowX][nowY].horse.back());
						mtrx[nowX][nowY].horse.pop_back();
						if (mtrx[nextX][nextY].horse.back() == &h[i])
							break;
					}

					for (Horse* horse : mtrx[nextX][nextY].horse) {
						(*horse).x = nextX;
						(*horse).y = nextY;
					}
					if (mtrx[nextX][nextY].horse.size() >= 4)
						return cnt;
				}

				h[i].dir = nextDir;
				if (mtrx[nowX][nowY].horse.size() >= 4)
					return cnt;

			}
			else if (mtrx[nextX][nextY].color == WHITE) {
				//다음칸이 WHITE면 현재 index의 말 위에 있는 모든 말과 함께 next로 이동(방향 안바뀜, xy는 바뀜)
				for (int p = 0; p < mtrx[nowX][nowY].horse.size(); p++) {
					if (mtrx[nowX][nowY].horse[p] == &h[i]) {
						mtrx[nextX][nextY].horse.insert(mtrx[nextX][nextY].horse.end(), mtrx[nowX][nowY].horse.begin() + p, mtrx[nowX][nowY].horse.end());
						mtrx[nowX][nowY].horse.erase(mtrx[nowX][nowY].horse.begin() + p, mtrx[nowX][nowY].horse.end());
						break;
					}
				}

				for (Horse* horse : mtrx[nextX][nextY].horse) {
					(*horse).x = nextX;
					(*horse).y = nextY;
				}

				if (mtrx[nextX][nextY].horse.size() >= 4)
					return cnt;
			}
			else {
				while(!mtrx[nowX][nowY].horse.empty()) {
					mtrx[nextX][nextY].horse.push_back(mtrx[nowX][nowY].horse.back());
					mtrx[nowX][nowY].horse.pop_back();
					if (mtrx[nextX][nextY].horse.back() == &h[i])
						break;
				}

				for (Horse* horse : mtrx[nextX][nextY].horse) {
					(*horse).x = nextX;
					(*horse).y = nextY;
				}
				if (mtrx[nextX][nextY].horse.size() >= 4)
					return cnt;
			}


		}
	}
	
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtrx[i][j].color;
		}
	}

	for (int i = 1; i <=K; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		r -= 1;
		c -= 1;
		h[i] = { i,r,c,dir };
		mtrx[r][c].horse.push_back(&h[i]);
	}

	cout<< func()<<"\n";

	return 0;
}