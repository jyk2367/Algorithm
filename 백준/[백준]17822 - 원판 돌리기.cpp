#include <bits/stdc++.h>
#include <unordered_set>
#define CLOCK 0
#define CCLOCK 1

using namespace std;

int N, M, T;
int x, d, k;

int mtrx[52][52];

double average() {
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (mtrx[i][j] != 0) {
				sum += mtrx[i][j];
				cnt++;
			}
		}
	}
	return (double)sum / cnt;
}

void rotate(int number) {
	if (d == CLOCK) {
		for (int r = k; r > 0; r--) {
			int tmp = mtrx[number][M - 1];
			for (int i = M - 2; i >= 0; i--) {
				mtrx[number][i + 1] = mtrx[number][i];
			}
			mtrx[number][0] = tmp;
		}
	}
	else {
		for (int r = k; r > 0; r--) {
			int tmp = mtrx[number][0];
			for (int i = 1; i < M; i++) {
				mtrx[number][i - 1] = mtrx[number][i];
			}
			mtrx[number][M - 1] = tmp;
		}
	}

}

void remove() {

	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (mtrx[i][j]!=0&&mtrx[i][j] == mtrx[i][(j + 1) % M]) {
				q.push({ i,j });
				q.push({ i,(j + 1) % M });
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mtrx[i][j] != 0 && mtrx[i][j] == mtrx[i + 1][j]) {
				q.push({ i,j });
				q.push({ i + 1, j });
			}
		}
	}

	if (q.size() == 0) {
		double avg = average();
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (mtrx[i][j] > 0) {
					if (mtrx[i][j] > avg)
						mtrx[i][j] -= 1;
					else if(mtrx[i][j]<avg)
						mtrx[i][j] += 1;
				}
			}
		}
	}
	else {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			mtrx[x][y] = 0;
		}
	}
}

int score() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			sum += mtrx[i][j];
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;
	for (int i = 1; i <=N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mtrx[i][j];
		}
	}
	
	while (T-- > 0) {
		cin >> x >> d >> k;

		for (int i = 1; i <= N; i++) {
			if(i%x==0)
				rotate(i);
		}
		
		remove();
	}

	cout << score()<<"\n";
}
