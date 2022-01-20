#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int num = x % y;
		x = y;
		y = num;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		int v[102];
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		long long result=0;
		for (int i = 0; i <N-1; i++) {
			for (int j = i + 1; j < N; j++) {
				result+= gcd(v[i], v[j]);
			}
		}
		cout << result << "\n";
	}
	
	return 0;
}