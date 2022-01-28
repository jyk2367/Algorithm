#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K, N;
	cin >> K >> N;
	long long line[10002];
	long long right = 0;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		right = max(right, line[i]);
	}

	sort(line, line + K);

	long long answer = 0;
	long long  left = 1;
	while (left <= right) {
		long long  mid = (left + right) / 2;

		long long cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += line[i] / mid;
		}
		
		if (cnt < N) {
			//mid로 나눈 값들을 다 더한게 N보다 작다면 mid가 크다는 뜻이므로 mid를 작게해주기 위해 right감소
			right = mid - 1;
		}
		else {
			//mid로 나눈 값들을 다 더한게 N과 같거나 크다면 mid가 작다는 뜻이므로 mid를 크게 해주기 위해 left증가
			left = mid + 1;
			answer = max(answer, mid);
		}
	}
	cout <<answer<< "\n";

	
	
	return 0;
}