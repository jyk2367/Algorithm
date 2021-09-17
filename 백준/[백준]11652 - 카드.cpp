#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	long long maxvalue;
	int maxcnt;
	int cnt;

	vector <long long> v;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int vSize = v.size();
	long long before;
	before = v[0];
	cnt = 1;
	maxcnt = 1;
	maxvalue = v[0];
	
	for (int i = 1; i < vSize; i++) {

		if (v[i] != before)
			cnt = 0;
		cnt++;
		before = v[i];
		if (maxcnt < cnt) {
			maxcnt = cnt;
			maxvalue = v[i];
		}
		else if (maxcnt == cnt) {
			if (maxvalue > v[i])
				maxvalue = v[i];
		}
	}
	cout << maxvalue;
}