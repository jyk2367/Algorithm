#include <bits/stdc++.h>
using namespace std;

int matrix[246913];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	matrix[0] = 1;
	matrix[1] = 1;
	for (int i = 2; i < 246913;i++) {
		for (int j = 2*i; j < 246913; j += i) {
			matrix[j]++;
		}
	}
	
	while (true) {
		int N;
		int cnt = 0;
		cin >> N;
		if (N == 0)
			break;
		for (int i = N+1; i <= 2 * N; i++) {
			if (matrix[i] == 0)
				cnt++;
		}
		cout << cnt << "\n";
		
	}
	
	
	return 0;
}