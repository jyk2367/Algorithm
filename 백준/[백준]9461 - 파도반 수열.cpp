#include <bits/stdc++.h>
using namespace std;
int N;
int answer;

long long dp[102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i < 101; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}


	while (N--) {
		int num;
		cin >> num;

		cout << dp[num] << "\n";

	}

	return 0;
}