#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v1, v2;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}
	sort(v1.begin(), v1.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		
		int left = 0,right=N-1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (v1[mid]<num)
				left = mid+1;
			else
				right = mid;
		}

		if (v1[left] == num)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	
	return 0;
}