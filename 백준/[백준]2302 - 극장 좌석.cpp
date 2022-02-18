#include <bits/stdc++.h>
using namespace std;

int N, M;
long long dp[42];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%2000000000;
	}

	cin >> N;
	cin >> M;
	int idx = 1;
	long long sum = 1;
	vector<int> v;
	while (M--) {
		int num;
		cin >> num;
		v.push_back(num-idx);
		idx = num + 1;
	}
	v.push_back(N+1 - idx);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0)
			continue;
		sum *= dp[v[i]]%2000000000;
	}

	cout << sum << "\n";

	return 0;
}