#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<string> v1,v2;

	for (int i = 0; i < N; i++) {
		string name, work;
		cin >> name >> work;
		
		
		if (work == "enter") {
			v1.push_back(name);
		}
		else {
			v2.push_back(name);
		}
	}

	sort(v1.begin(), v1.end(),greater<string>());
	sort(v2.begin(), v2.end(),greater<string>());

	for (int i = 0,j=0; i < v1.size();i++) {
		if (j < v2.size()&&v1[i] == v2[j]) {
			j++;
			continue;
		}
		cout << v1[i] << "\n";
	}


	return 0;
}