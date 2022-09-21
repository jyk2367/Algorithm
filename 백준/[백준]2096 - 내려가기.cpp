#include <iostream>
#include <algorithm>

using namespace std;

// 줄, 0 ~ 2, 0:최대 점수, 1:최소 점수
int score[3][2];
int lastScore[3][2];
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int input;
	for (int i = 1; i <=N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input;
			score[j][0] = input;
			score[j][1] = input;
		}

		score[0][0] += max(lastScore[0][0], lastScore[1][0]);
		score[0][1] += min(lastScore[0][1], lastScore[1][1]);
		score[1][0] += max(lastScore[0][0], max(lastScore[1][0], lastScore[2][0]));
		score[1][1] += min(lastScore[0][1], min(lastScore[1][1], lastScore[2][1]));
		score[2][0] += max(lastScore[1][0], lastScore[2][0]);
		score[2][1] += min(lastScore[1][1], lastScore[2][1]);

		lastScore[0][0] = score[0][0];
		lastScore[0][1] = score[0][1];
		lastScore[1][0] = score[1][0];
		lastScore[1][1] = score[1][1];
		lastScore[2][0] = score[2][0];
		lastScore[2][1] = score[2][1];
	}

	cout << max(score[0][0],max(score[1][0],score[2][0])) << " " << min(score[0][1], min(score[1][1], score[2][1]));
	return 0;
}