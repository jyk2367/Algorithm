#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N;i++) {
		int input;
		cin >> input;
		if (v.size() == 0 || v.back() < input) {
			v.push_back(input);
			continue;
		}
		*lower_bound(v.begin(), v.end(), input) = input;
	}

	cout << v.size() << "\n";
	
	
	return 0;
}