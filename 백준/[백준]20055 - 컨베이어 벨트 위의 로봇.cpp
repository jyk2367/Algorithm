#include <bits/stdc++.h>
#define IN 1
using namespace std;
int N, K;//칸수 : 2*N+1개, 
int A[202];//내구도
bool robot[202];

/*
1번 위치 : 올리는위치
N번 위치 : 내리는위치
로봇은 올리는위치에만 올림
로봇이 내리는 위치에 도착하면 즉시내림
로봇은 스스로 이동가능, 올리는위치or 이동 칸 내구도 -1

1.벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
2.가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
2-1.로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
3.올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
4.내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
*/

int zeroA_cnt() {
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (A[i] == 0)
			cnt++;
	}
	return cnt;
}

void rotate_belt() {
	int tmp = A[2*N];
	for (int i = 2*N; i>=2; i--) {
		A[i] = A[i - 1];
	}
	A[1] = tmp;
	for (int i = N; i >= 2; i--) {
		robot[i] = robot[i - 1];
	}
	robot[N]=0;
	robot[1]=0;
}

void move_robot() {
	for (int i = N - 1; i >= 2; i--) {
		if (A[i + 1] > 0 && robot[i + 1] == 0 && robot[i] == 1) {
			robot[i + 1] = 1;
			robot[i] = 0;
			A[i + 1]--;
		}
	}
	if (robot[N] == 1)
		robot[N] = 0;
}

void put_robot() {
	if (A[IN] > 0) {
		A[IN]--;
		robot[IN] = 1;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <=2*N; i++) {
		cin >> A[i];
	}

	int cnt = 0;
	while (true) {
		cnt++;
		
		rotate_belt();
		move_robot();//내구도 1이상으로 이동, N이면 바로 로봇제거

		put_robot();
		if (zeroA_cnt() >= K)
			break;
	}

	cout << cnt << "\n";

		
	return 0;
}