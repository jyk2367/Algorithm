#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A,B,len;
	int num = 0;
	vector<int> answer;

	cin >> A>>B;
	cin >> len;
	for (int i = len; i>=1; i--) {
		int tmp;
		cin >> tmp;
		num+=tmp* pow(A, i-1);
	}
	while (num != 0) {
		answer.push_back(num % B);
		num /= B;
	}
	
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}