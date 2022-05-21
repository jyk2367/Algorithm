#include<bits/stdc++.h>

using namespace std;

int M, N;
int snack[1000000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int left=1,right=0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> snack[i];
		right = max(right, snack[i]);
	}

	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt += snack[i] / mid;
		}
		if (cnt < M) {
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	cout << left-1 << "\n";
	return 0;
}