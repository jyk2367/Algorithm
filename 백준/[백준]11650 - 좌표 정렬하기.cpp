#include <bits/stdc++.h>
using namespace std;

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
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first<<" " << v[i].second << "\n";
	}

	return 0;
}