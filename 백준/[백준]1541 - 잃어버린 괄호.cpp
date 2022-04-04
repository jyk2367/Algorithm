#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define min(x,y) (x>y?x:y)

using namespace std;
int VSIZE;
vector<string> v;
int sum=0;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	string tmp;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '-') {
			v.push_back(tmp);
			v.push_back("-");
			tmp = "";
		}
		else if (input[i] == '+') {
			v.push_back(tmp);
			v.push_back("+");
			tmp = "";
		}
		else 
			tmp += input[i];
	}
	v.push_back(tmp);
	VSIZE = v.size();
	bool state = true;
	int plus=0, minus=0;
	for (int i = 0; i < VSIZE; i++) {
		if (v[i] == "-")
			state = false;
		if (v[i] == "-" || v[i] == "+")
			continue;

		if (state == true) {
			plus += stoi(v[i]);
		}
		if (state == false) {
			minus += stoi(v[i]);
		}
	}
	cout << plus-minus << "\n";

	return 0;
}