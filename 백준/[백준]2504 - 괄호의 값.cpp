#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	string s;
	cin >> s;
	int result = 1, tmp = 0, sum = 0;
	bool state = false;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			result *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[') {
			result *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				state = true;
				break;
			}
			if (s[i-1]=='(')
				sum += result;
			st.pop();
			result /= 2;
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() != '[') {
				state = true;
				break;
			}
			if (s[i-1]=='[')
				sum += result;
			st.pop();
			result /= 3;
		}
	}
	if (!st.empty() || state)
		cout << 0 << "\n";
	else
		cout << sum<<"\n";
}
