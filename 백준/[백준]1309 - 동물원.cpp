#include <iostream>

using namespace std;

int dp[100'002];
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i-2])% 9901;
	}

	cout << dp[N] << "\n";
	
	return 0;
}