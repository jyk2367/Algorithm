#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer=0;
	int N, C;
	cin >> N >> C;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	
	int left =0, right = v.back();
	
	while (left<=right) {
		int selected = 1;
		int pre_idx = 0;
		int mid = (left + right) / 2; // 최대 거리
		for (int i = 1; i < N; i++) {
			if (v[i] - v[pre_idx] >= mid) {
				pre_idx = i;
				selected++;
			}
		}

		if (selected < C) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	
	cout << right << "\n";
	
	return 0;

}