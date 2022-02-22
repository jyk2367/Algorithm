#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;

	cin >> s1;
	cin >> s2;
	int S1LEN = s1.length();
	int S2LEN = s2.length();

	for (int i = 1; i <= S1LEN; i++) {
		for (int j = 1; j <= S2LEN; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[S1LEN][S2LEN]<<"\n";

	

	return 0;
}