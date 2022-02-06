#include <bits/stdc++.h>
using namespace std;

long long m[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	while (true) {
		stack<int> st;

		cin >> N;
		if (N == 0)
			break;
		
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		m[N] = -1;

		long long answer = 0;
		for (int i = 0; i <=N; i++) {
			while (st.size()>0 && m[i] < m[st.top()]) {
				int pos = st.top();
				st.pop();
				int len = st.empty() ? i : i - st.top()-1;
				answer = max(len*m[pos], answer);
			}
			st.push(i);
		}

		cout << answer << "\n";
	}
	return 0;
}