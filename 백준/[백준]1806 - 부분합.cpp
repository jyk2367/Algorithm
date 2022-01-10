#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[100000];
	int N, S, sp = 0, ed = 0, sum = 0;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int answer = 0x7fffffff;
	while(sp<N&&ed<N||sum>=S) {
		if (sum >=S) {
			sum -= A[ed];
			answer = min(answer, sp - ed);
			ed++;
		}
		else {// sum<=S
			sum += A[sp++];
		}
	}
	if (answer == 0x7fffffff)
		cout << 0 << "\n";
	else
		cout << answer << "\n";

	return 0;
}