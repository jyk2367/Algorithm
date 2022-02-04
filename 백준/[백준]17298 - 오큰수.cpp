#include <bits/stdc++.h>

using namespace std;
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	stack<pair<int,int>> st;
	vector<int> v;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(-1);
		if (st.empty()) {
			st.push({ input, i });
		}
		else {
			while (!st.empty()) {
				if (st.top().first < input) {
					v[st.top().second] = input;
					st.pop();
				}
				else
					break;
			}
			st.push({ input, i });
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << v[i]<<" ";
	}
	

	return 0;
}