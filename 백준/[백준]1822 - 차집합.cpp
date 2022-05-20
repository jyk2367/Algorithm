#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	int s1Size=0,cnt = 0;
	cin >> A >> B;
	set<int> s1,s2;
	for (int i = 0; i < A; i++) {
		int input;
		cin >> input;
		s1.insert(input);
		s1Size++;
	}
	for (int i = 0; i < B; i++) {
		int input;
		cin >> input;
		if (s1.count(input) == 1) {
			s1.erase(input);
			cnt++;
		}
	}

	cout << s1Size -cnt << "\n";
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}