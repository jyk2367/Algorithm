#include <bits/stdc++.h>
using namespace std;

int N,M,S,E;
int mtrx[2002];
bool dp[2002][2002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <=N; i++) {
		cin >> mtrx[i];
		dp[i][i] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (mtrx[i] == mtrx[i + 1])
			dp[i][i + 1] = true;
	}

	for (int i = N; i >=1 ; i--) {
		for (int j = N; j >=i; j--) {
			if (i == j|| i + 1 > j - 1) {
				continue;
			}

			dp[i][j] = dp[i + 1][j - 1] && (mtrx[i] == mtrx[j]);
		}
	}

	cin >> M;

	while (M--) {
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}
	

	return 0;
}
