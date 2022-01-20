#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int N;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}