#include <bits/stdc++.h>
using namespace std;
string N;
int answer;

int dp[5002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	N=" "+N;
	int len = N.length();

	if (N[0] == '0') {
		cout << 0 << endl;
		return 0;
	}

	dp[0] = 1;
	for (int i = 1; i <= len; i++) {
		int num = N[i] - '0';
		int addn = (N[i - 1]-'0') * 10 + num;
		if (num > 0 && num <= 9)
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;

		if (i == 1)
			continue;

		if (addn >= 10 && addn <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}
	
	cout << dp[len-1] << "\n";


	return 0;

}