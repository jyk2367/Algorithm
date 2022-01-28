#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;
	vector<long long> v;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}

	long long left = 0, right = 1000000000,answer=0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		
		long long total = 0;
		for (int i = 0; i < N;i++) {
			total += (v[i]-mid>0? v[i] - mid:0);
		}

		if (total < M)
			right = mid - 1;
		else {
			left = mid + 1;
			answer = max(mid, answer);
		}
	}
	cout << answer << "\n";

	return 0;
}