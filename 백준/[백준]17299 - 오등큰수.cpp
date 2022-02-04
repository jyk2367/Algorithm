#include <bits/stdc++.h>

using namespace std;
int N;
int arr[1000002];
int num[1000002];
int answer[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	stack<pair<int,int>> st;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		answer[i] = -1;
		num[arr[i]]++;
	}
	
	for (int i = 0; i < N; i++) {
		if (st.empty()) {
			st.push({ arr[i], i});
		}
		else {
			while (!st.empty()&& num[st.top().first] < num[arr[i]]) {
				answer[st.top().second] = arr[i];
				st.pop();
			}
			st.push({ arr[i],i });
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}