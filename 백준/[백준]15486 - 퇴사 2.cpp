#include <bits/stdc++.h>
using namespace std;

int dp[1500002];
int T[1500002];
int P[1500002];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i <=N+1; i++) {
		dp[i] = max(dp[i], dp[i-1]);
		if (i + T[i] <= N+1) {
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		}
	}

	cout << dp[N + 1]<<"\n";

	return 0;
}