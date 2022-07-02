#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int dice[10];
int answer;
int piece[4];

int mtrx[34];	//다음 갈 위치 저장
int score[34];	//점수
int turn[34];	//전환지점
bool check[34];	//중복체크용

void func(int k,int sum) {
	if (k == 10) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int origin = piece[i];
		int now = piece[i];
		int mvCnt = dice[k];

		if (turn[now] > 0) {
			now = turn[now];
			mvCnt--;
		}

		while (mvCnt-- > 0)
			now = mtrx[now];

		//도착했거나 중복이면 skip
		if (now != 21 && check[now])
			continue;

		check[origin] = false;
		check[now] = true;
		piece[i] = now;

		func(k + 1, sum + score[now]);

		piece[i] = origin;
		check[now] = false;
		check[origin] = true;

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 21; i++)	mtrx[i] = i + 1;
	mtrx[21] = 21;
	for (int i = 22; i < 27; i++)	mtrx[i] = i + 1;
	mtrx[27] = 20; mtrx[28] = 29; mtrx[29] = 30;
	mtrx[30] = 25; mtrx[31] = 32; mtrx[32] = 25;

	turn[5] = 22; turn[10] = 31; turn[15] = 28;

	for (int i = 0; i < 21; i++) 	score[i] = 2 * i;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[26] = 30; score[27] = 35;
	score[28] = 28; score[29] = 27; score[30] = 26;
	score[31] = 22; score[32] = 24;


	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	func(0,0);
	
	cout << answer << "\n";

	return 0;
}