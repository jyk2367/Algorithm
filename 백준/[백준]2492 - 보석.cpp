#include <iostream>

using namespace std;

int N, M, T, K;
int A, B;

struct Node {
	int x;
	int y;
};

Node node[102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T >> K;
	for (int i = 0; i < T; i++) {
		cin >> node[i].x>>node[i].y;
	}


	int answer = 0;
	Node answerNode={0,0};
	for (int i = 0; i <T; i++) {
		for (int j = 0; j < T; j++) {
			int wX=node[i].x, wY=node[j].y;

			//윈도우 범위가 정사각형을 벗어나면
			if (wX + K > N) {
				wX = N - K;
			}
			if (wY + K > M) {
				wY = M - K;
			}

			int cnt = 0;
			for (int k = 0; k < T; k++) {
				int nodeX = node[k].x;
				int nodeY = node[k].y;
				if (wX <= nodeX && nodeX <= wX + K
					&& wY <= nodeY && nodeY <= wY + K) {
					cnt++;
				}
			}
			if (answer < cnt) {
				answer = cnt;
				answerNode = {wX,wY};
			}
		}
	}

	cout << answerNode.x << " " << answerNode.y + K << "\n";
	cout << answer << "\n";


	return 0;
}