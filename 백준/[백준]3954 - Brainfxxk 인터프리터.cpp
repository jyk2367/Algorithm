#include <iostream>
#include <stack>
using namespace std;

int T;
int M, C, I;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		int M, C, I;
		string cmd, input;
		cin >> M >> C >> I;
		cin >> cmd >> input;
		
		int ptr = 0, input_ptr = 0, cnt = 0;
		int data[100'001] = {};
		int command[4096] = {};
		int result = 0x7fff'ffff;
		
		//1. [, ] 위치 index 저장
		stack<int> st;
		for (int i = 0; i < C; i++) {
			if (cmd[i]=='[') {
				st.push(i);
			}
			else if (cmd[i] == ']') {
				int tmp = st.top();
				command[i] = tmp;
				command[tmp] = i;
				st.pop();
			}
		}

		bool state = false;
		for (int i = 0; i < C; i++) {
			switch (cmd[i]) {
			case '-':
				data[ptr] = (data[ptr] + 255) % 256;
				break;
			case '+':
				data[ptr] = (data[ptr] + 1) % 256;
				break;
			case '<':
				ptr = (ptr - 1 + M) % M;
				break;
			case '>':
				ptr = (ptr + 1) % M;
				break;
			case '[':
				if (data[ptr] == 0) {
					i = command[i];
				}
				break;
			case ']':
				if (data[ptr] != 0) {
					i = command[i];
				}
				break;
			case ',':
				data[ptr] = ((input_ptr >= I) ? 255 : (int)input[input_ptr++]);
				break;
			}

			cnt++;

			if (cnt >= 50'000'000) {
				result = min(result, i);
			}

			if (cnt >= 100'000'000) {
				state = true;
			}

			if (state) {
				cout << "Loops " << result << " " << command[result] << "\n";
				break;
			}
		}

		if (!state) {
			cout << "Terminates\n";
		}
	}

	return 0;
}