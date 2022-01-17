#include <bits/stdc++.h>
using namespace std;

int dp[502];
int A[102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, answer = 0;
	int num1, num2;
	cin >> N;
	vector<pair<int, int>> v;
	v.push_back({ 0,0 });
	for (int i = 1; i <= N; i++) {
		cin >> num1 >> num2;
		v.push_back({num1, num2});
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <i; j++) {
			if(v[j].second<v[i].second)
				dp[i] = max(dp[i], dp[j]+1);
		}
		answer = max(answer,dp[i]);
	}



	
	cout << N- answer << "\n";
	return 0;
}