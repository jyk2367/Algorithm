#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int A[20002],B[20002];


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N>>M;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		sort(B, B + M);
		int sum = 0;

		for (int i = 0; i < N; i++) {
			int left = 0, right = M;

			while (left <right) {
				int mid = (left + right) / 2;
				if (A[i]>=B[mid]) {
					left = mid+1;
				}
				else {
					right = mid - 1;
				}
			}
			sum += left;
		}
		cout << sum << "\n";
	}

	return 0;
}
