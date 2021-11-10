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
		//괄호를 열때 계산을 먼저 하기
		//이 문제는 분배법칙을 생각하면 쉽게 풀수있는 문제
		// (() [[]] )([])
		// 2*(2+3*3)+2*3
		// (2*2)+(2*3*3)+(2*3)
		
		// ex)
		// s[i]를 한개씩 받아가면서 stack에 집어넣으면서
		// stack에 있는 '('의 개수가 2개면 2를 두번 곱한것
		// stack에 있는 '('의 개수가 3개면 2를 세번 곱한것
		// stack에 있는 '('의 개수가 3개면 2를 세번 곱한것
		// stack에 있는 '('의 개수가 3개, ')'의 개수가 2개면 2를 세번. 3을 두번 곱한것
		// stack에 있는 '('의 개수가 1개. ')'의 개수가 3개면 2를 한번, 3을 세번 곱한것
		// stack은 하나씩 확인하기 어려우므로 vector로 풀어도 무방할 듯함
		//(단 문자열의 길이가 30이라고 했으므로 vector의 크기를 미리 30으로 지정하는게 시간복잡도상 좋아보임).
		

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

// 괄호 () 내에 두개의 값이 존재하는 경우에 대한 처리가 없다. (2 9) = (2+9)*2 = 22

/*

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	string s;
	cin >> s;
	int result = 1, tmp = 0, sum = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')') {
			if (st.empty() || st.top() == '[') {
				sum = 0;
				break;
			}
			result *= 2;
			if (st.top() != '(') {
				result *= st.top();
				st.pop();
			}
			st.pop();
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() == '(') {
				sum = 0;
				break;
			}
			result *= 3;
			if (st.top() != '[') {
				result *= tmp;
				st.pop();
			}
			st.pop();
		}
		else {
			tmp = s[i] - '0';
			st.push(tmp);
		}

		if ((s[i] == ')' || s[i] == ']') && (s[i + 1] == '(' || s[i + 1] == '[')) {
			sum += result;
			result = 1;
		}
	}
	if (!st.empty())
		sum = 0;
	cout << sum;
}*/