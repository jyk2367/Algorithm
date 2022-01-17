#include <bits/stdc++.h>
using namespace std;

int dp[1002][2];
int A[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int answer = 0;

	for (int i = 1; i <= N; i++) {
		int num = 0,num2=0;
		for (int j = i-1; j >= 0; j--) {
			if (A[i] > A[j])
				num = max(num, dp[j][0]);
			if (A[i] < A[j])
				num2 = max(num2, max(dp[j][0],dp[j][1]));
		}
		dp[i][0] = num + 1;
		dp[i][1] = num2 + 1;
		answer = max(answer,max(dp[i][0], dp[i][1]));
	}


	cout << answer<< "\n";
	return 0;
}