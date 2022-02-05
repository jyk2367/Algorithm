#include <bits/stdc++.h>

using namespace std;
int N, inputLen;
double answer;
string input;
int alphabet[27];
stack<double> st;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> input;
	for (int i =0; i <N; i++) {
		cin >> alphabet[i];
	}
	inputLen = input.length();
	for (int i = 0; i < inputLen; i++) {
		if (isalpha(input[i])) {
			st.push(alphabet[input[i]-'A']);
		}
		else {
			double op2 = st.top();
			st.pop();
			double op1 = st.top();
			st.pop();

			switch (input[i]) {
			case '*':
				st.push(op1 * (double)op2);
				break;
			case '+':
				st.push(op1 + op2);
				break;
			case '-':
				st.push(op1 - op2);
				break;
			case '/':
				st.push(op1 / (double)op2);
				break;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}