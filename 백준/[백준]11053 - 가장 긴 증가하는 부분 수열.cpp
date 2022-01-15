#include <bits/stdc++.h>
using namespace std;
int N;
int answer;

int A[1002];
int dp[1002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 1; i <=N;i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {

		int sum = 0;
		for (int j = 1; j < i; j++) {
			if(A[j]<A[i])
			sum = max(sum, dp[j]);
		}
		dp[i] = sum + 1;
		answer = max(answer,dp[i]);
	}


	cout << answer << "\n";

	return 0;

}