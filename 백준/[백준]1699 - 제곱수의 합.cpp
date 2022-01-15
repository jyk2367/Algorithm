#include <bits/stdc++.h>
using namespace std;
int N;
int answer;

int dp[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;


	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <=N; i++) {
		dp[i] = i;
		int num = 1;
		while (num * num <= i) {
			dp[i] = min(dp[i - (num * num)] + 1,dp[i]);
			num++;
		}
	}


	cout << dp[N] << "\n";

	return 0;

}