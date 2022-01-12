#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;
string s[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,M;
	cin >> N>>M;
	unordered_map<string, int> hm;

	for (int i = 1; i <=N; i++) {
		cin >> s[i];
		hm[s[i]] = i;
	}

	while (M--) {
		string query;
		cin >> query;
		if (isdigit(query[0]))
			cout << s[stoi(query)] << "\n";
		else
			cout << hm[query] << "\n";
	}

	return 0;
}