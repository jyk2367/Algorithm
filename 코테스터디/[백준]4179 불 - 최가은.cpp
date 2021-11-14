#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
#define X first
#define Y first

int R, C;
int maze1[MAX][MAX]; //불의 이동
int maze2[MAX][MAX]; //지훈이의 이동
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(queue<pair<int, int>> p1, pair<int, int>p2, int R, int C) {
	queue<pair<int, int>> q1;//불의 이동용 queue
	queue<pair<int, int>> q2;//지훈이의 이동용 queue

	int PSIZE = p1.size();//지금 문제에서는 p1.size()를 넣어도 상관없지만 나중가면 시간복잡도때문에 이것처럼 따로설정해야 할때가 있다


	//불의 위치 넣기
	for (int i = 0; i < PSIZE; i++) { 
		pair<int, int> p = p1.front();
		p1.pop();
		q1.push(make_pair(p.first, p.second));
	}

	//지훈이 위치 넣기
	q2.push(p2);


	
	while (!q1.empty()) {
		pair<int, int> p = q1.front();
		q1.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dx[i];
			int next_y = p.second + dy[i];

			if (next_x >= R || next_x < 0 || next_y >= C || next_y < 0)
				continue;
			//벽이 있거나 이미 값이 0이상 존재하면 스킵(0 이상 존재한다는건 이미 visited했다는 뜻이므로)
			if (maze1[next_x][next_y] >= 0 || maze1[next_x][next_y] == -2)
				continue;
			q1.push(make_pair(next_x, next_y));
			maze1[next_x][next_y] = maze1[p.first][p.second] + 1;
		}
	}


	while (!q2.empty()) {
		pair<int, int> p = q2.front();
		q2.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dx[i];
			int next_y = p.second + dy[i];

			//next_x,next_y가 범위밖을 나오면 아래 코드들을 뚫고 밖으로 나왔단 뜻이므로 출력하고 프로그램 종료
			if (next_x >= R || next_x < 0 || next_y >= C || next_y < 0) {
				cout << maze2[p.first][p.second] + 1;
				return;
			}
			//벽이 있거나 이미 값이 0이상 존재하면 스킵(0 이상 존재한다는건 이미 visited했다는 뜻이므로)
			if (maze2[next_x][next_y] >= 0 || maze2[next_x][next_y] == -2)
				continue;
			//불이 간 곳의 count와 비교해서 지훈이의 count+1이 더 크다면 스킵(불이 먼저 갔다는 뜻이므로)
			if (maze1[next_x][next_y] != -1 && maze1[next_x][next_y] <= maze2[p.first][p.second] + 1)
				continue;

			q2.push(make_pair(next_x, next_y));
			maze2[next_x][next_y] = maze2[p.first][p.second] + 1;
		}
	}
	//위 범위밖으로 나왔을때 코드를 못뚫었기 때문에 impossible
	cout << "IMPOSSIBLE";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	pair<int, int> p2; //지훈이 위치는 하나이므로 pair 한개
	queue<pair<int, int>> p1;//불의 위치는 여러개일 수 있으므로 queue
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			//1. 벽인 경우 -2
			if (input[j] == '#') {
				maze1[i][j] = -2;
				maze2[i][j] = -2;
			}
			//2. 불인 경우 maze1(불)에서는 0, maze2(지훈이)의 경우 벽과 동일하게 -2로 취급, maze1의 bfs시작점으로 쓰임
			else if (input[j] == 'F') {
				p1.push(make_pair(i, j));
				maze1[i][j] = 0;
				maze2[i][j] = -2;
			}
			//3. 지훈이의 위치는 따로 저장+ maze1(불)에서는 벽과 동일하게 -2로 취급, maze2(지훈이)의 경우 0, maze2의 bfs시작점으로 쓰임
			else if (input[j] == 'J') {
				p2= make_pair(i, j); //지훈이의 첫 위치 저장용 pair
				maze1[i][j] = -2;
				maze2[i][j] = 0;
			}
			//4. '.' 점으로 지나갈 수 있는 공간들
			else {
				maze1[i][j] = -1;
				maze2[i][j] = -1;
			}
		}
	}

	/*for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << maze1[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << maze2[i][j] << " ";
		}
		cout << "\n";
	}*/


	bfs(p1, p2, R, C);

	/*for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << maze1[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << maze2[i][j] << " ";
		}
		cout << "\n";
	}*/

	
	return 0;
}