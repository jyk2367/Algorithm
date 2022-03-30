#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int now = 0,sum=0;
	for (int i = 0; i < N; i++) {
		now = now + v[i];
		sum += now;
	}
	cout << sum << "\n";
	return 0;
}