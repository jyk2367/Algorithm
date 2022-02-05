#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string input;
int inputLen;
stack<char> operand;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> input;
	inputLen = input.length();


	for (int i = 0; i < inputLen; i++) {
		if (isalpha(input[i])) {
			cout << input[i]; 
			continue;
		}

		if (input[i] == '(') {
			operand.push(input[i]);
			continue;
		}
		
		if (input[i] == ')') {
			while (operand.top() != '(') {
				cout << operand.top();
				operand.pop();
			}
			operand.pop();
			continue;
		}

		if (input[i] == '*' || input[i] == '/') {
			//이전 연산자가 우선순위가 낮으면 출력하지 않고 넣어둠
			//이전 연산자가 우선순위가 같으면 이전것들은 출력함
			while (!operand.empty() && (operand.top() == '*' || operand.top() == '/')) {
				cout << operand.top();
				operand.pop();
			}
		}
		else {
			//+,-보다 우선순위 낮은 연산자는 없으므로 스택이 비거나 괄호시작이 나올때까지 출력
			while (!operand.empty()&&operand.top()!='(') {
				cout << operand.top();
				operand.pop();
			}
		}
		operand.push(input[i]);
	}

	while (!operand.empty()) {
		cout << operand.top();
		operand.pop();
	}

	return 0;
}