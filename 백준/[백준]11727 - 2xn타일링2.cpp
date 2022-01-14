#include <bits/stdc++.h>
using namespace std;
int N;
int answer;
int dp[1002];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; i++) {
		if (i % 2 == 0) {
			dp[i] = (dp[i - 1]*2 + 1)%10007;
		}
		else
			dp[i] = (dp[i - 1] * 2 - 1)%10007;
	}


	cout << dp[N]<<"\n";
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int N;
int answer;
void func(int k, int sum) {
	if (k > N)
		return;
	if (k == N) {
		answer += sum;
		return;
	}
	func(k + 1, sum * 1);
	func(k + 2, sum * 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	func(0, 1);

	cout << answer % 10007 << "\n";
	return 0;
}
*/