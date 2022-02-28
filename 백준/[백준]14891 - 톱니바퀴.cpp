#include <bits/stdc++.h>
using namespace std;

int gear[5][8];
int rotated[5];
int T;

void rotate(int gearNumber,int dir) {
	if (rotated[gearNumber])
		return;
	rotated[gearNumber] = true;

	if (gearNumber - 1 >= 1 && gear[gearNumber][6] != gear[gearNumber - 1][2] && !rotated[gearNumber - 1])
		rotate(gearNumber - 1, 0 - dir);
	if (gearNumber + 1 <= 4 && gear[gearNumber][2] != gear[gearNumber + 1][6] && !rotated[gearNumber + 1])
		rotate(gearNumber + 1, 0 - dir);

	if (dir == 1) {//시계방향
		int tmp = gear[gearNumber][7];
		for (int i = 7; i >= 1; i--) {
			gear[gearNumber][i] = gear[gearNumber][i - 1];
		}
		gear[gearNumber][0] = tmp;
	}
	else {//반시계
		int tmp = gear[gearNumber][0];
		for (int i = 0; i <= 6; i++) {
			gear[gearNumber][i] = gear[gearNumber][i + 1];
		}
		gear[gearNumber][7] = tmp;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <=4; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = tmp[j] - '0';
		}
	}
	cin >> T;

	while (T--) {
		int whichGear, dir;
		cin >> whichGear >> dir;

		memset(rotated, 0, sizeof(rotated));
		rotate(whichGear,dir);
	}
	int answer = 0;
	if (gear[1][0] == 1)
		answer += 1;
	if (gear[2][0] == 1)
		answer += 2;
	if (gear[3][0] == 1)
		answer += 4;
	if (gear[4][0] == 1)
		answer += 8;

	cout << answer << "\n";

	return 0;
}