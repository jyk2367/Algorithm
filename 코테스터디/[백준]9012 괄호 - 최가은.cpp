//#include <stdio.h> : 생략(<iostream>만 사용해도 cout,printf,scanf,cin등 사용가능)
#include <iostream>
#include <string>  //#include <string.h> : <string>으로 대체, cstring==string.h==c언어에서 주로 사용
#include <stack>
#define MAX 51
using namespace std;

int main() {
	ios::sync_with_stdio(0);//무시해도됨(c와 c++에서 입출력(printf,scanf,cout,cin 연결 끊기)
	cin.tie(0);//무시해도됨(cout과 cin 같은버퍼 해제)
	//자세한 사항은 https://jaimemin.tistory.com/1521 참조,이해못해도 무방
	//위 두줄을 쓴 경우 c언어에서 쓰는 표준입출력은 사용하면 안됨(연결끊어놓음)
	//getchar로 버퍼지울필요없어서 편리!!


	string s;//char배열이 아닌 string으로 대체
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> s;
		int outLoop_break = 0;
		
		stack<char>stack;

		for (int i = 0; i < s.length(); i++) {//MAX가 아니라 입력받은 문자열의 길이만큼 for문 돌게 함
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
			//else //입력값은 '('or ')'이므로 굳이 다른값 생각하지 않아도 된다
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


//원본
/*
int main() {
	char s[MAX];//string으로 대체
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