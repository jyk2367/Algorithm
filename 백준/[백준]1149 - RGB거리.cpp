#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[100002][4];
int cost[1002][4];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> cost[i][j];
		}
	}
	
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	dp[1][3] = cost[1][3];
	for (int i = 2; i <= N; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];
	}
	
	cout << *min_element(dp[N]+1,dp[N]+4);
}
