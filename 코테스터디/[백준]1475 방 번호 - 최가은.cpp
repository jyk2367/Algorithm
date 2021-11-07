#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> setList;
	for (int i = 0; i < 10; i++)
		setList.push_back(0);

	for (int x = 0; x < s.length(); x++) {
		int number = s[x] - '0';
		++setList[number];
	}

	setList[6] = (setList[6] + setList[9]) / 2 + (setList[6] + setList[9]) % 2;
	setList[9] = 0;

	int max = 0;
	for (int y = 0; y < 9; y++) {
		if (max < setList[y])
			max = setList[y];
	}
	cout<<max;
	return 0;
}