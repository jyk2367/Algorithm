#include <bits/stdc++.h>
using namespace std;

int T;
long long dp[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= N; i++) {
			dp[i] =(dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
		}
		cout << dp[N] % 1000000009 << "\n";
		
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}