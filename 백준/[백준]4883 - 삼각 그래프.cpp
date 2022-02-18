#include <bits/stdc++.h>
using namespace std;

int graph[100000][3];
int dp[100000][3];
int T=1,N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (T) {
		cin >> N;

		if (N == 0)
			break;


		cin >> graph[0][0] >> graph[0][1] >> graph[0][2];
		dp[0][0] = graph[0][1];
		dp[0][1] = graph[0][1];
		dp[0][2] = min(graph[0][1]+graph[0][2],graph[0][1]);
		int idx = 1;
		for (int i = 1; i < N; i++) {
			cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
			dp[i][1] = min(dp[i][0],min(dp[i - 1][0], min(dp[i - 1][1], dp[i-1][2]))) + graph[i][1];
			dp[i][2] = min(dp[i][1],min(dp[i - 1][1] , dp[i - 1][2] ))+ graph[i][2];
		}

		cout << T<<". "<<dp[N - 1][1] << "\n";
		T++;
	}
	

	return 0;
}