#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= N; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	
	if(dp[N] == 1)
		cout <<"SK" << "\n";
	else
		cout << "CY" << "\n";

	return 0;
}