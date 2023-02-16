#include <bits/stdc++.h>
#define EMPTY -2
#define BLACK -1
#define RAINBOW 0
#define BLOCKSIZE 22

using namespace std;

int N, M;


int color[BLOCKSIZE][BLOCKSIZE];
bool visited[BLOCKSIZE][BLOCKSIZE];
bool rainbowVisited[BLOCKSIZE][BLOCKSIZE];
int Score;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

struct Block {
	int groupSize;
	int groupScore;
	pair<int, int> startPos;
	int rainbowCount;
	vector<pair<int, int>> blocks;

	Block() {
		groupSize = 0;
		groupScore = 0;
		rainbowCount = 0;
		startPos = { 0,0 };
	}

};


Block bfs(int x, int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rainbowVisited[i][j] = false;
		}
	}

	queue<pair<int, int>> q;
	Block result;

	q.push({ x,y });
	visited[x][y] = true;
	result.blocks.push_back({x,y});

	int startColor = color[x][y];

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nextX = nowX+ dx[dir];
			int nextY = nowY + dy[dir];

			if (nextX<0 || nextX>=N || nextY >=N || nextY < 0)
				continue;
			if (color[nextX][nextY] == BLACK)
				continue;

			if (color[nextX][nextY] == RAINBOW) {
				if (!rainbowVisited[nextX][nextY]) {
					rainbowVisited[nextX][nextY] = true;

					q.push({ nextX, nextY });
					result.rainbowCount++;
					result.blocks.push_back({ nextX, nextY });
				}
			}
			else if (color[nextX][nextY] == startColor) {
				if (!visited[nextX][nextY]) {
					visited[nextX][nextY] = true;

					q.push({ nextX, nextY });
					result.blocks.push_back({ nextX, nextY });
					
				}
			}
			


		}
	}
	result.groupSize = result.blocks.size();
	result.startPos = { x,y };

	return result;
}


void Init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void removeBlock(Block b) {
	int bblockSize = b.blocks.size();
	for (int i = 0; i < bblockSize; i++) {
		color[b.blocks[i].first][b.blocks[i].second] = EMPTY;
	}
}

bool blockCompare(const Block &a, const Block &b){
	if (a.groupSize < b.groupSize) {
		return false;
	}
	else if(a.groupSize == b.groupSize){
		if (a.rainbowCount < b.rainbowCount) {
			return false;
		}
		else if (a.rainbowCount == b.rainbowCount) {
			if (a.startPos.first < b.startPos.first) {
				return false;
			}
			else if (a.startPos.first == b.startPos.first) {
				if (a.startPos.second <= b.startPos.second) {
					return false;
				}
			}
		}
		
	}

	return true;
}



Block searchBiggestBlock() {
	Block biggestBlock;
	biggestBlock.groupSize = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] || color[i][j] == BLACK || color[i][j] == EMPTY || color[i][j] == RAINBOW)
				continue;
			Block b = bfs(i, j);
			
			if (biggestBlock.groupSize == 0) {
				biggestBlock = b;
			}
			else if(blockCompare(b, biggestBlock)){
				biggestBlock = b;
			}
		}
	}

	return biggestBlock;
}


void gravity() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (color[j][i] == EMPTY) {
				int x = j;
				int y = i;
				while (x > 0 && color[x][y] == EMPTY)
					x--;
				if (color[x][y] == BLACK) 
					continue;
				color[j][i] = color[x][y];
				color[x][y] = EMPTY;
			}
		}
	}
}

void rotate() {
	int tmp[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = color[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			color[i][j] = tmp[j][N - 1 - i];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> color[i][j];
		}
	}

	while (1) {
		Init();

		//1. 크기가 가장 큰 블록 그룹을 찾는다. 
		//그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹, 그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을, 그 것도 여러개이면 열이 가장 큰 것을 찾는다.
		
		Block block = searchBiggestBlock();
		
		if (block.groupSize<2)
			break;
		Score += (block.groupSize * block.groupSize);
		//2.1에서 찾은 블록 그룹의 모든 블록을 제거한다. 블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.
		removeBlock(block);


		//3.격자에 중력이 작용한다.
		gravity();

		//4.격자가 90도 반시계 방향으로 회전한다.
		rotate();

		//5.다시 격자에 중력이 작용한다.
		gravity();

	}
	cout << Score << "\n";

	return 0;
}