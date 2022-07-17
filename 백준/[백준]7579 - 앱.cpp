#include <iostream>

using namespace std;


int N, M;
int m[102];
int c[102];
//D[i][j] : i번째 앱까지 고려했을 때 '최소' j만큼의 cost를 사용한 최대 메모리의 양
int dp[102][10002];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <=N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <=N; i++) {
		cin >> c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j < c[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
		}
	}	

	int ans = 0;
	for (int j = 0; j <= 10000; j++) {
		if (dp[N][j] >= M) {
			ans = j;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}