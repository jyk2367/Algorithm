#include <bits/stdc++.h>
#define MOD 1000000000 
using namespace std;
long long dp[102];
long long A[10];
long long B[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	//init
	A[0] = 0;
	for (int i = 1; i <10; i++) {
		A[i] = 1;
	}
	dp[1] = 9;

	N -= 1;
	int answer = dp[1];
	while(N--){
		answer = 0;
		for (int i = 0; i < 10; i++) {
			if (i + 1 < 10)
				B[i + 1]=(B[i+1]+A[i]) % MOD;
			if (i - 1>=0)
				B[i - 1]=(B[i-1]+A[i]) % MOD;
		}
		for (int i = 0; i < 10; i++) {
			answer=(answer+B[i])%MOD;
			A[i] = B[i];
			B[i] = 0;
		}
	}
	
	cout << answer<< "\n";

	return 0;
}