#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	string s;
	if (N == 0) {
		cout << 0 << "\n";
		return 0;
	}

	while (N != 0) {
		if (N % -2 == 0) {
			N /= -2;
			s += "0";
		}
		else {
			if (N>0) {
				N /= -2;
				s += "1";
			}
			else {
				N = (N - 1) / -2;
				s += "1";
			}
		}
	}

	string t(s.rbegin(), s.rend());
	cout << t << "\n";

	return 0;
}