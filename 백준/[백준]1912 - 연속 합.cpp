#include <bits/stdc++.h>
using namespace std;
int N;
int answer=-1002;

int A[100002];
int dp[100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 1; i <=N;i++) {
		cin >> A[i];
		if (dp[i-1] < 0)
			dp[i] = A[i];
		else
			dp[i] = dp[i - 1] + A[i];
		answer=max(dp[i], answer);
	}

	cout << answer << "\n";

	return 0;

}