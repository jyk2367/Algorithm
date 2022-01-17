#include <bits/stdc++.h>
using namespace std;

int dp[32];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;

	for (int i = 4; i <= N; i++) {
		if (i % 2 != 0)
			dp[i] = 0;
		else {
			dp[i] += dp[i - 2] * dp[2];
			int idx = i-2;
			int m = 2;
			while (idx - m > 0) {
				dp[i] += dp[idx - m] * 2;
				m += 2;
			}
			dp[i] += 2;
		}
	}


	cout << dp[N] << "\n";
	return 0;
}