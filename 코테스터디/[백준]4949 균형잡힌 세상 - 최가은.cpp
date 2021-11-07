#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define FALSE 0
#define TRUE 1

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> circle;
	stack<char> rect;

	while (true) {
		char s[100] = { 0, };
		cin.getline(s, 100, '.');

		if (s[0] == '.')//��������
			break;

		int result = TRUE;

		for (int i = 0; i < 100; i++) {
			if (s[i] == '(')
				circle.push(s[i]);
			else if (s[i] == ')') {
				if (circle.empty()) {
					cout << "no1\n";
					result = FALSE;
					break;
				}
				circle.pop();
			}

			if (s[i] == '[')
				rect.push(s[i]);
			else if (s[i] == ']') {
				if (rect.empty()) {
					cout << "no2\n";
					result = FALSE;
					break;
				}
				rect.pop();
			}
		}

		if (result == FALSE)
			continue;
		else if (circle.empty() && rect.empty())
			cout << "yes\n";
		else
			cout << "no3\n";
	}
}

/*
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> circle;
	stack<char> rect;

	while (true) {
		char s[100] = { 0, };
		cin.getline(s, 100, '.');

		if (s[0] == '.')//��������
			break;

		int result = TRUE;

		for (int i = 0; i < 100; i++) {
			if (s[i] == '(')
				circle.push(s[i]);
			else if (s[i] == ')') {
				if (circle.empty()) {
					cout << "no1\n";
					result = FALSE;
					break;
				}
				circle.pop();
			}

			if (s[i] == '[')
				rect.push(s[i]);
			else if (s[i] == ']') {
				if (rect.empty()) {
					cout << "no2\n";
					result = FALSE;
					break;
				}
				rect.pop();
			}
		}

		if (result == FALSE)
			continue;
		else if (circle.empty() && rect.empty())
			cout << "yes\n";
		else
			cout << "no3\n";
	}
}
*/