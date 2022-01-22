#include <bits/stdc++.h>
using namespace std;


int dp[10];

void twoCheck(int num) {
	int div = 2;
	while (num/div>=1) {
		dp[2]+= num / div;
		div *= 2;
	}
}

void fiveCheck(int num) {
	int div = 5;
	while (num / div >= 1) {
		dp[5]+=num/div;
		div *= 5;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	fiveCheck(N);
	twoCheck(N);
	cout << min(dp[2], dp[5]) << "\n";

	return 0;
}