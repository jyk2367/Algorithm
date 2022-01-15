#include <bits/stdc++.h>
using namespace std;
int N,K;
int answer;

int dp[202][202];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>K;
	dp[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		dp[0][i] = 1;
		dp[1][i] = i;
	}
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i-1][j]+dp[i][j-1])%1000000000;
		}
	}
	cout << dp[N][K] << "\n";

	return 0;

}