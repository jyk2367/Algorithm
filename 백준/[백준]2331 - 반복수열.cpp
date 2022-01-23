#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> answer;
	int A, P;
	cin >> A >> P;
	int now = A;
	answer.push_back(now);
	while (true) {
		int sum = 0;
		while (now>0) {
			int n = now % 10;
			now /= 10;
			sum += pow(n,P);
		}
		now = sum;
		if (find(answer.begin(), answer.end(), now) != answer.end())
			break;
		answer.push_back(now);
	}

	int recursive_point = now;
	int cnt = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == recursive_point)
			break;
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}