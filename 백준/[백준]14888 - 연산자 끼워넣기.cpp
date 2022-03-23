#include <iostream>
using namespace std;
int N;
int operand[12];
int oper[4];

long long maxResult = -10000'00001;
long long minResult = 10000'00001;

void func(int k,long long sum) {
	if (k == N) {
		maxResult = max(maxResult, sum);
		minResult = min(minResult, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i] -= 1;
			
			switch (i) {
			case 0:
				func(k + 1, sum+operand[k]);
				break;
			case 1:
				func(k + 1, sum - operand[k]);
				break;
			case 2:
				func(k + 1, sum * operand[k]);
				break;
			case 3:
				func(k + 1, sum / operand[k]);
				break;
			}
			
			oper[i] += 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin>>operand[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	func(1,operand[0]);

	cout << maxResult << "\n";
	cout << minResult << "\n";


	return 0;
}