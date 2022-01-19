#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int answer = 0;
	vector<int> v;
	v.push_back(0x80000000);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (v.back() < num) {
			v.push_back(num);
			answer++;
		}
		else {
			*lower_bound(v.begin(), v.end(), num)=num;
		}
	}

	cout << answer << "\n";

	return 0;
}