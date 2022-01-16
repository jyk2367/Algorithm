#include <bits/stdc++.h>
using namespace std;
int answer;
int dp[10];
int A[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		A[i] = 1;
	}
	int answer =10;
	N -= 1;
	while (N--) {
		for (int i = 1; i < 10; i++) {
			dp[i] = (dp[i-1] + A[i]) % 10007;
			A[i] = dp[i] % 10007;
			answer= (answer+dp[i]) % 10007;
		}
	}
	cout << answer <<"\n";

	return 0;
}