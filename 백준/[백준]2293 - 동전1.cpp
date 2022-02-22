#include <bits/stdc++.h>
using namespace std;

int N, K;
int coin[102];
int dp[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i <N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j] += dp[j-coin[i]];
		}
	}
	cout << dp[K] << "\n";

	

	return 0;
}