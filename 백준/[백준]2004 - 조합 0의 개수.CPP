#include <bits/stdc++.h>
using namespace std;

long long dp[10];

void divCheckPlus(long long num,int div) {
	long long d = div;
	while (num / d >= 1) {
		dp[div]+=num/d;	
		d *= div;
	}
}

void divCheckMinus(long long num,int div) {
	long long d = div;
	while (num/d>= 1) {
		dp[div]-=num/d;
		d *= div;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,r;
	cin >> n>>r;

	divCheckPlus(n,5);
	divCheckMinus(r, 5);
	divCheckMinus(n - r, 5);

	divCheckPlus(n, 2);
	divCheckMinus(r, 2);
	divCheckMinus(n - r, 2);
	

	cout << min(dp[2],dp[5])<<"\n";

	return 0;
}