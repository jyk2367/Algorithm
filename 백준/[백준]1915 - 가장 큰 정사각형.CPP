#include <bits/stdc++.h>
using namespace std;
int N, M;
int dp[1002][1002];
int mtrx[1002][1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;
	cin >> N >> M;
	for (int i = 1; i <=N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j <M; j++) {
			mtrx[i][j+1]=tmp[j]-'0';
			if (tmp[j] == '1') {
				dp[i][j+1] = 1;
				answer = 1;
			}
		}
	}

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=M; j++) {
			if (dp[i][j]!=1)
				continue;

			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer*answer << "\n";
	

	return 0;
}