#include <bits/stdc++.h>
using namespace std;

int dp[1002];
int A[1002];
int track[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int idx = 0;
	int answer = 0;
	vector<int> v;

	for (int i = 1; i <=N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[j] + 1,dp[i]);
			}
		}
		if (answer < dp[i]) {
			answer = dp[i];
			idx = i;
		}
	}
	for (int i = idx; i >= 1; i--) {
		if (dp[i] == answer) {
			v.push_back(A[i]);
			answer--;
		}
	}

	cout << v.size() << "\n";

	for (int i = v.size() - 1; i >= 0;i--) {
		cout << v[i] << " ";
	}


	return 0;
}