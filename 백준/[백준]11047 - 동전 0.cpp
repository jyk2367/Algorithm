#include <iostream>
#include <string>

using namespace std;

int coin[12];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
	int sum = 0;
	for (int i = N; i >= 1; i--) {
		if (K == 0)
			break;
		if (K / coin[i] > 0) {
			sum += K / coin[i];
			K = K % coin[i];
		}
	}
	cout << sum;
}
