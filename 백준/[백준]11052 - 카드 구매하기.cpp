#include <bits/stdc++.h>
using namespace std;
int N;
int answer;
int dp[1002];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> p;
	p.push_back(0);//index맞추기용
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		p.push_back(num);
	}

	dp[1] = p[1];
	dp[2] = max(dp[1]*2, p[2]);
	for (int i = 3; i <= N; i++) {
		int idx = 1;
		dp[i] = p[i];
		while (idx <= i / 2) {
			dp[i] = max(dp[i], dp[idx] + dp[i - idx]);
			idx++;
		}
	}
	cout << dp[N] << "\n";
	return 0;

}