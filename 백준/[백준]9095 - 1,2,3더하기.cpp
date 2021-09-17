#include <iostream>
#include <string>

using namespace std;


int dp[10000002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int X;
	cin >> X;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;


	for (int i = 0; i < X; i++) {
		int num;
		cin >> num;
		
		for (int j = 4; j <= num; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[num]<<"\n";
	}
}
