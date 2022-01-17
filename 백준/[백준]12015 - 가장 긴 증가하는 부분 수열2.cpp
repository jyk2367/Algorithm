#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int num;
	int answer = 0;
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> num;

		if (num > v.back()) {
			v.push_back(num);
			answer++;
		}
		else {
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
			*it=num;
		}
	}
	cout << answer << "\n";
	return 0;
}