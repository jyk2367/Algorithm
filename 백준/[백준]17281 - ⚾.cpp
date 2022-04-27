#include <bits/stdc++.h>
#define NONE -1

using namespace std;

// 9개짜리 배열 - 선수 순서
vector<int> order(9);

int arr[52][10];
bool visited[10];

int N;
int answer;

void score() {
	int ening = 1;
	int total = 0;
	int idx = 0;
	while (ening <= N) {
		int out = 0;
		int base[4] = { -1,-1,-1,-1 };
		bool onBoard[10] = { 0 };
		while (true) {
			if (out == 3)
				break;

			if (onBoard[order[idx % 9]]) {
				idx++;
				continue;
			}

			switch (arr[ening][order[idx % 9]]) {
			case 0:
				out++;
				break;
			case 1://안타
				if (base[3] != NONE) {
					total++;
					onBoard[base[3]] = false;
					base[3] = NONE;
				}
				if (base[2] != NONE) {
					base[3] = base[2];
					base[2] = NONE;
				}
				if (base[1] != NONE) {
					base[2] = base[1];
					base[1] = NONE;
				}
				base[1] = order[idx % 9];
				onBoard[order[idx % 9]] = true;
				break;
			case 2://2루타
				if (base[3] != NONE) {
					total++;
					onBoard[base[3]] = false;
					base[3] = NONE;
				}
				if (base[2] != NONE) {
					total++;
					onBoard[base[2]] = false;
					base[2] = NONE;
				}
				if (base[1] != NONE) {
					base[3] = base[1];
					base[1] = NONE;
				}
				base[2] = order[idx % 9];
				onBoard[order[idx % 9]] = true;
				break;
			case 3:
				if (base[3] != NONE) {
					total++;
					onBoard[base[3]] = false;
					base[3] = NONE;
				}
				if (base[2] != NONE) {
					total++;
					onBoard[base[2]] = false;
					base[2] = NONE;
				}
				if (base[1] != NONE) {
					total++;
					onBoard[base[1]] = false;
					base[1] = NONE;
				}
				base[3] = order[idx % 9];
				onBoard[order[idx % 9]] = true;
				break;
			case 4:
				if (base[3] != NONE) {
					total++;
					onBoard[base[3]] = false;
					base[3] = NONE;
				}
				if (base[2] != NONE) {
					total++;
					onBoard[base[2]] = false;
					base[2] = NONE;
				}
				if (base[1] != NONE) {
					total++;
					onBoard[base[1]] = false;
					base[1] = NONE;
				}
				total++;
				break;
			}
			idx++;
		}

		ening++;
	}
	answer = max(total, answer);
}

void func(int k) {
	if (k == 9) {
		//정해진 선수 순서대로 1~N이닝까지 얻는 최대점수
		score();
		return;
	}
	if (k == 3) {
		func(k + 1);
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (!visited[i]) {
				visited[i] = true;
				order[k] = i;
				func(k + 1);
				visited[i] = false;
			}
		}
	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	// 1번 선수를 4번타자로 미리 결정
	visited[0] = true;
	order[4] = 0;

	func(0);

	cout << answer << "\n";


	return 0;
}