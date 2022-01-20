#include <bits/stdc++.h>
using namespace std;

int A[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		int num=0;
		cin >> num;
		A[num]++;
	}
	
	for (int i = 1; i <= 10000; i++) {
		while (A[i]-- > 0) {
			cout << i << "\n";
		}
	}
	
	return 0;
}