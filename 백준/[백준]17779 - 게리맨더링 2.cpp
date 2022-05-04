#include <bits/stdc++.h>

using namespace std;

int N;
int population[22][22];
int area[22][22];
int minVal = 0x7fff'ffff;

int getVal() {
	int maxPopu = 0;
	int minPopu = 0x7fffffff;
	int areaCnt[6] = { 0 };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			areaCnt[area[i][j]] += population[i][j];
		}
	}

	for (int i = 1; i <= 5; i++) {
		minPopu = min(areaCnt[i], minPopu);
		maxPopu = max(areaCnt[i], maxPopu);
	}
	return maxPopu - minPopu;
}

void divideArea(const int& x, const int& y, const int& d1, const int& d2) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			area[i][j] = 5;
		}
	}

	// 2 4 2 2

	//area1
	for (int p = 1; p < x; p++) {
		for (int q = 1; q <= y; q++) {
			area[p][q] = 1;
		}
	}

	for (int p = x, Y = y - 1; p < x + d1; p++, Y--) {
		for (int q = 1; q <= Y; q++) {
			area[p][q] = 1;
		}
	}
	

	//area2
	for (int p = 1; p <= x; p++) {
		for (int q = y+1; q <= N; q++) {
			area[p][q] = 2;
		}
	}

	for (int p = x+1, Y = y+2; p <=x+d2; p++, Y++) {
		for (int q = Y; q <= N; q++) {
			area[p][q] = 2;
		}
	}

	//area3
	for (int p = x+d1+d2; p <= N; p++) {
		for (int q = 1; q < y-d1+d2; q++) {
			area[p][q] = 3;
		}
	}

	for (int p = x + d1 + d2, Y = y - d1 + d2; x + d1 <= p; p--, Y--) {
		for (int q = 1; q <Y; q++) {
			area[p][q] = 3;
		}
	}

	//area4
	for (int p = x + d1 + d2 + 1; p <= N; p++) {
		for (int q = y - d1 + d2; q <= N; q++) {
			area[p][q] = 4;
		}
	}

	for (int p = x + d1 + d2, Y = y - d1 + d2 + 1; x + d2 < p; p--, Y++) {
		for (int q = Y; q <=N; q++) {
			area[p][q] = 4;
		}
	}
	
	//cout << "\n";
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << area[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";
}

void func() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if ((d1 >= 1) && (d2 >= 1) &&
						(1 <= x) && (x < x + d1 + d2) && (x + d1 + d2 <= N) &&
						(1 <= y - d1) && (y - d1 < y) && (y < y + d2) && (y + d2 <= N)) {

						//cout << x << " " << y << " " << d1 << " " << d2 << "\n";
						divideArea(x,y,d1,d2);

						minVal = min(getVal(), minVal);
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> population[i][j];
			area[i][j] = 5;
		}
	}

	func();

	cout << minVal << "\n";


	return 0;
}