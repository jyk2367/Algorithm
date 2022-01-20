#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, string>& p1, const pair<int, string>& p2) {
	return p1.first < p2.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int,string>> v;
	int N;
	cin >> N;
	while (N--) {
		int num1;
		string num2;
		cin >> num1>>num2;
		v.push_back({ num1,num2 });
	}
	stable_sort(v.begin(), v.end(),compare);

	int VSIZE = v.size();
	for (int i = 0; i < VSIZE; i++) {
		cout << v[i].first<<" " << v[i].second << "\n";
	}

	return 0;
}