#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int mtrx[52][52];
vector<pair<pair<int, int>, int>> rotation;

void rotate(int arr[][52],const int &r,const int &c, const int &s) {
	int sx = r - s;
	int sy = c - s;
	int ex = r + s;
	int ey = c + s;

	int temp = arr[sx][sy];
	
	for (int i = sx+1; i <= ex; i++) {
		arr[i - 1][sy] = arr[i][sy];
	}

	for (int j = sy + 1; j <= ey; j++) {
		arr[ex][j - 1] = arr[ex][j];
	}

	for (int i = ex - 1; i >= sx; i--) {
		arr[i+1][ey] = arr[i][ey];
	}

	for (int j = ey - 1; j >= sy;j--) {
		arr[sx][j + 1] = arr[sx][j];
	}

	arr[sx][sy + 1] = temp;
}

int func() {
	int tmp[52][52];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j]=mtrx[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int r = rotation[i].first.first;
		int c = rotation[i].first.second;
		int s = rotation[i].second;

		for (int j = 1; j <= s; j++) {
			rotate(tmp, r, c, j);
		}

		//for (int t = 1; t <= N; t++) {
		//	for (int j = 1; j <= M; j++) {
		//		cout << tmp[t][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}
	
	int value = 0x7fff'ffff;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += tmp[i][j];
		}
		value = min(value, sum);
	}

	return value;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mtrx[i][j];
		}
	}
	
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rotation.push_back({ {r,c} ,s });
	}

	sort(rotation.begin(), rotation.end());
	
	int answer = 0x7fff'ffff;
	do {
		//for (int i = 0; i < rotation.size(); i++) {
		//	cout << rotation[i].first.first << " " << rotation[i].first.second << " " << rotation[i].second << endl;
		//}

		answer = min(answer,func());
	} while (next_permutation(rotation.begin(), rotation.end()));

	cout << answer << "\n";

	return 0;
}