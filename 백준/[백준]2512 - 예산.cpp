#include<bits/stdc++.h>

using namespace std;

int M, N;
int arr[10002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int left = 0, right=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}
	cin >> M;

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] <= mid) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum <=M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << left - 1<<"\n";


	return 0;
}