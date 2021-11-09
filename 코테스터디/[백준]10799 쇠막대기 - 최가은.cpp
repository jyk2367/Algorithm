#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	string s;
	cin >> s;
	int count = 0;
	stack<char> st;
	
	//string의 문자 하나씩 확인하면서
	//이전 값이 여는 괄호'('였다면 레이저이므로 stack의 사이즈를 추가
	//이전 값이 닫는 괄호')'였다면 막대의 끝부분이므로 count의 사이즈를 1 추가
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (s[i - 1] == '(') {
				st.pop();
				count += st.size();
				//i++; //왜 더하기?
			}
			else {
				count++;
				st.pop();
			}

		}

	}
	count += st.size();
	cout << count;
	return 0;
}

/*
* int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	string s;
	cin >> s;
	int count = 0;
	stack<char> st;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (s[i - 1] == '(') {
				st.pop();
				count += st.size();
				i++;
			}
			else {
				count++;
				st.pop();
			}
			cout << count << "\n";
		}

	}
	count += st.size();
	cout << count;
	return 0;
}
*/