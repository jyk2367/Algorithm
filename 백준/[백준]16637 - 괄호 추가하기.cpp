#include <iostream>

using namespace std;

int N;
int answer=0x80000000;
string input;

int calc(int a, char op,int b) {
	switch (op) {
	case '+':
		a += b;
		break;
	case '-':
		a -= b;
		break;
	case '*':
		a *= b;
		break;
	}
	return a;
}


void func(int k,int result) {
	if (k >= N) {
		answer = max(answer, result);
		return;
	}

	// 맨 처음껀 항상 '+' 
	char op = (k == 0) ? '+' : input[k - 1];

	//괄호 묶기
	if (k + 2 < N) {
		int b = calc(input[k] - '0', input[k + 1],input[k + 2] - '0');
		func(k + 4, calc(result, op, b));
	}

	//괄호 안묶기
	func(k + 2, calc(result, op,input[k]-'0'));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cin >> input;
	
	func(0,0);

	cout << answer << "\n";
	
	return 0;
}
​