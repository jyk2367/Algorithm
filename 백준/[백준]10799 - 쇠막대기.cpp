#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string stick;
	cin >> stick;

	int answer = 0;
	int N = stick.length();
	stack<char> st;
	for (int i = 0; i < N; i++) {
		if (stick[i] == '(')
			st.push('(');
		else {
			if (stick[i - 1] == '(') {
				st.pop();
				answer += st.size();
			}
			else {
				st.pop();
				answer++;
			}
			
		}
	}
	
	cout << answer << "\n";
	
	return 0;
}