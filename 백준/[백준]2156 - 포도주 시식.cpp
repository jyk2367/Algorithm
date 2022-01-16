#include <bits/stdc++.h>
using namespace std;
int answer;
int dp[10003];
int A[10003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	dp[1] = A[1];
	dp[2] = A[1]+A[2];
	answer = dp[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + A[i], dp[i - 3] + A[i - 1] + A[i]));
		answer = max(answer,dp[i]);
	}

	cout <<answer<<"\n";

	return 0;
}