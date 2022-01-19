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
		track[i] = -1;
		for (int j = 1; j <i; j++) {
			if (A[i] > A[j]&&dp[i]<dp[j]+1) {
				dp[i] = dp[j] + 1;
				track[i] = j;
			}
		}

		if (dp[i] > answer) {
			answer = dp[i];
			idx = i;
		}
	}
	
	while (idx != -1) {
		v.push_back(A[idx]);
		idx = track[idx];
	}
	
	cout << answer << "\n";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}


	return 0;
}