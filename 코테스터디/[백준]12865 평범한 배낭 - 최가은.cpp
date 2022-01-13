#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;

//평범한 배낭
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int w[MAX], v[MAX],dp[103][MAX];
	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= K; j++)
			if (j >= w[i])    
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
	}
	cout << dp[N][K] << endl;
}