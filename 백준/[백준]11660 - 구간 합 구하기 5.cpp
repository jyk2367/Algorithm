#include <bits/stdc++.h>
using namespace std;

int N,M;
int mtrx[1030][1030];
int dp[1030][1030];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> mtrx[i][j];
			dp[i][j] = mtrx[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	
	int x1, y1, x2, y2;
	while (M--) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";

	}

	return 0;
}