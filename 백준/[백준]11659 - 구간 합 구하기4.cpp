#include <iostream>
#include <string>

using namespace std;

int dp[100002];
int number[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin >> N>>M;
	int num1, num2,sum=0;
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}

	dp[1] = number[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1]+number[i];
	}


	
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		cout << dp[num2] - dp[num1-1]<<"\n";
	}
}
