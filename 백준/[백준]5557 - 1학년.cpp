#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

long long answer = 0;

int N;
int arr[102];

long long dp[102][22];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[1][arr[0]] = 1;
	for (int i = 1; i <N; i++) {
		for (int j = 0; j <=20; j++) {
			if (j - arr[i - 1] >= 0) {
				dp[i][j] += dp[i - 1][j - arr[i - 1]];
			}
			if (j + arr[i - 1] <=20) {
				dp[i][j] += dp[i - 1][j + arr[i - 1]];
			}
		}
	}

	cout << dp[N-1][arr[N - 1]] << "\n";
	
	
	return 0;
}
​