#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int N,k;
	cin >> N>>k;
	while (N--) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cout << v[k-1] << "\n";
	
	return 0;
}