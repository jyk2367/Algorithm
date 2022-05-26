#include <bits/stdc++.h>

using namespace std;

// -1'000'000'000        -1 0 1        1'000'000'000
int N;
int A[100002];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int left = 0, right= N-1;
	int liq = abs(A[left] + A[right]);
	int first=A[left], second=A[right];

	while (left < right) {
		int sum = A[left]+A[right];
		if (abs(sum) < liq) {
			liq = abs(sum);
			first = A[left];
			second = A[right];
		}

		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else
			break;
	}

	cout << first + second << "\n";


	return 0;
}
