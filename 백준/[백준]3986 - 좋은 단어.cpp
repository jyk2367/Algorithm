#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int answer=0;
	while (N--) {
		string tmp;
		cin >> tmp;
		int TLEN = tmp.size();
		stack<int> st;
		for (int i = 0; i < TLEN; i++) {
			if (st.empty()) {
				st.push(tmp[i]);
			}
			else {
				if (st.top() == tmp[i])
					st.pop();
				else
					st.push(tmp[i]);
			}
		}
		
		if (st.empty())
			answer++;
	}
	cout << answer << "\n";

	return 0;
}