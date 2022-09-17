#include <iostream>


using namespace std;

int T;

bool isFolded(string& s) {
	if (s.length() == 1)
		return true;

	int LEN = s.length() / 2;
	string s_front = s.substr(0, LEN);
	string s_end = s.substr(LEN + 1);

	for (int i = 0; i < LEN; i++) {
		if (s_front[i] == s_end[(LEN - 1) - i]) {
			return false;
		}
	}
	return isFolded(s_front);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		
		if (isFolded(s))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	
	return 0;
}