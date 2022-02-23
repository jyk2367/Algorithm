#include <bits/stdc++.h>
using namespace std;

int T,N,M;
int coin[22];
int dp[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		cin >> M;

		dp[0] = 1;
		for (int i =0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << "\n";

	}
	
	return 0;
}