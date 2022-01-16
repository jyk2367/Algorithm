#include <bits/stdc++.h>
using namespace std;
int answer;
int dp[3][100003];
int A[2][100003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T,N;
	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}

		dp[0][0] = A[0][0];
		dp[1][0] = A[1][0];
		dp[2][0] = 0;
		for (int i = 1; i < N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + A[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + A[1][i];
			dp[2][i] = max(dp[0][i - 1],max( dp[1][i - 1],dp[2][i-1]));
		}
		
		cout << max(dp[0][N - 1], max(dp[1][N - 1], dp[2][N - 1]))<<"\n";

	}

	return 0;
}