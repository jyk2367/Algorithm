#include <bits/stdc++.h>

using namespace std;
int N;
void func(int k, int index, vector<int> &answer, vector<int>& lotto) {
	if (k == 6) {
		for (int i = 0; i < 6; i++) {
			cout << answer[i]<<" ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = index; i < N; i++) {
		answer.push_back(lotto[i]);
		func(k + 1, i + 1, answer, lotto);
		answer.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> N;
		if (N == 0)
			break;
		vector<int> lotto;
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			lotto.push_back(input);
		}
		vector<int> answer;
		func(0, 0,answer,lotto);
		cout << "\n";

	}

	return 0;
}