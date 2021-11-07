//#include <stdio.h> : ����(<iostream>�� ����ص� cout,printf,scanf,cin�� ��밡��)
#include <iostream>
#include <string>  //#include <string.h> : <string>���� ��ü, cstring==string.h==c���� �ַ� ���
#include <stack>
#define MAX 51
using namespace std;

int main() {
	ios::sync_with_stdio(0);//�����ص���(c�� c++���� �����(printf,scanf,cout,cin ���� ����)
	cin.tie(0);//�����ص���(cout�� cin �������� ����)
	//�ڼ��� ������ https://jaimemin.tistory.com/1521 ����,���ظ��ص� ����
	//�� ������ �� ��� c���� ���� ǥ��������� ����ϸ� �ȵ�(����������)
	//getchar�� ���������ʿ��� ��!!


	string s;//char�迭�� �ƴ� string���� ��ü
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> s;
		int outLoop_break = 0;
		
		stack<char>stack;

		for (int i = 0; i < s.length(); i++) {//MAX�� �ƴ϶� �Է¹��� ���ڿ��� ���̸�ŭ for�� ���� ��
			if (s[i] == '(')
				stack.push(s[i]);
			else if (s[i] == ')') {
				if (stack.empty()) {
					cout<<("NO\n");
					outLoop_break = 1;
					break;
				}
				stack.pop();
			}
			//else //�Է°��� '('or ')'�̹Ƿ� ���� �ٸ��� �������� �ʾƵ� �ȴ�
				//continue;
		}

		if (outLoop_break == 1)
			continue;
		else if (stack.empty())
			cout<<("YES\n");
		else 
			cout<<("NO\n");

	}

	return 0;
}


//����
/*
int main() {
	char s[MAX];//string���� ��ü
	int T;
	scanf_s("%d", &T);
	getchar();

	for (int i = 0; i < T; i++) {
		scanf_s("%s", s);
		getchar();
		int outLoop_break = 0;

		stack<char>stack;
		for (int i = 0; i < MAX; i++) {
			if (s[i] == '(')
				stack.push(s[i]);
			else if (s[i] == ')') {
				if (stack.empty()) {
					printf("NO\n");
					outLoop_break = 1;
					break;
				}
				stack.pop();
			}
			else 
				continue;
		}

		if (outLoop_break == 1)
			continue;
		else if (stack.empty())
			printf("YES\n");
		else 
			printf("NO\n");

	}

	return 0;
}
*/