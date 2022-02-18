#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[2000002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[999999] = 1;
	dp[1000000] = 0;
	dp[1000001] = 1;
	if (N > 0) {
		N += 1000000;
		for (int i = 1000002; i <= N; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2])%1000000000;
		}
	}
	else {
		N += 1000000;
		for (int i = 999998; i >= N; i--) {
			dp[i] = (dp[i + 2] - dp[i + 1])%1000000000;
		}
	}

	if (dp[N] > 0) {
		cout << 1 << "\n";
		cout << dp[N] << "\n";
	}
	else if (dp[N] < 0) {
		cout << -1 << "\n";
		cout << abs(dp[N]) << "\n";
	}
	else {
		cout << 0 << "\n";
		cout << 0 << "\n";
	}

	return 0;
}