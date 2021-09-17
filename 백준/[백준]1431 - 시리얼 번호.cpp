#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
	if (a.size()!= b.size())
		return a.size()<b.size();
	else{
		int num1 = 0, num2 = 0;
		for (int i = 0; i < a.size(); i++) {
			if (isdigit(a[i]))
				num1 += a[i] - '0';
			if (isdigit(b[i]))
				num2 += b[i] - '0';
		}
		if (num1!=num2)
			return num1<num2;
		if (a != b)
			return a < b;
		else
			return false;
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin() , v.end(), compare);

	int vSize = v.size();
	for (int i = 0; i < vSize; i++) {
		cout << v[i]<<"\n";
	}

}