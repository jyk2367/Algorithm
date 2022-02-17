#include <bits/stdc++.h>
using namespace std;

int dp[502][502];
int tri[502][502];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	
	dp[1][1] = tri[1][1];
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i][j], tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]));
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[N][i]);
	}
	cout << answer << "\n";
	return 0;
}