#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int N = s.length();
	vector<string> v;
	for (int i = 0; i < N; i++) {
		v.push_back(s.substr(i));
	}
	sort(v.begin(), v.end());

	int VSIZE = v.size();
	for (int i = 0; i < VSIZE; i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}