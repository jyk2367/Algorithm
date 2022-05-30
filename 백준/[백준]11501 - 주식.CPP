#include <bits/stdc++.h>
using namespace std;

int T, N;
int num[1'000'002];
int biggest;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		long long sum = 0;
	
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		biggest = num[N - 1];
		for (int i = N - 1; i >= 0; i--) {
			if (biggest < num[i]) {
				biggest = num[i];
			}
			else {
				sum += biggest - num[i];
			}
		}
		
		cout << sum << "\n";

	}

	return 0;
}
