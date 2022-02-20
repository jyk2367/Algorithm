#include <bits/stdc++.h>
using namespace std;

int T, W;
int fall[1010];
int dp[1010][2][32];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T >> W;

	for (int i = 1; i <=T; i++) {
		cin >> fall[i];

		for (int j = 0; j <= W; j++) {
			if (j == 0) {
				dp[i][0][j] = dp[i - 1][0][j] + (fall[i] == 1 ? 1 : 0);
			}
			else {
				dp[i][0][j] = max(dp[i - 1][0][j] + (fall[i] == 1 ? 1 : 0), dp[i - 1][1][j - 1] + (fall[i] == 1 ? 1 : 0));
				dp[i][1][j] = max(dp[i - 1][1][j] + (fall[i] == 2 ? 1 : 0), dp[i - 1][0][j - 1] + (fall[i] == 2 ? 1 : 0));
			}
		}

	}

	int answer = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= W;j++) {
			answer = max(dp[T][i][j], answer);
		}
	}

	cout << answer << "\n";

	return 0;
}