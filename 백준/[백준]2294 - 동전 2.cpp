#include <bits/stdc++.h>
using namespace std;

int N,K;
int dp[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>K;

	for (int i = 1; i < 10002; i++) {
		dp[i] = 1000000;
	}

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		dp[num] = 1;
	}
	
	for (int i = 1; i <= K; i++) {
		for (int j = i/2; j<=i; j++) {
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}
	if(dp[K]>= 1000000)
		cout << -1 << "\n";
	else
		cout << dp[K] << "\n";

	return 0;
}