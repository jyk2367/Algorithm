#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int,int>> v;
	int N;
	cin >> N;
	while (N--) {
		int num1,num2;
		cin >> num1>>num2;
		v.push_back({ num1,num2 });
	}
	sort(v.begin(), v.end(),compare);

	int VSIZE = v.size();
	for (int i = 0; i < VSIZE; i++) {
		cout << v[i].first<<" " << v[i].second << "\n";
	}

	return 0;
}