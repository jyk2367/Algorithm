#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[10002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int p1=0, p2=0;
	int sum = 0,cnt=0;
	while (p1 <= 10000 && p2 <=10000) {
		if (sum < M) {
			sum += A[p2++];
		}
		else if (sum > M) {
			sum -= A[p1++];
		}
		else {
			cnt++;
			sum -= A[p1++];
		}
	}
	cout << cnt << "\n";
	
}