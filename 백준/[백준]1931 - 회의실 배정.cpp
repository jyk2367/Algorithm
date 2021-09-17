#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1000002];
vector<pair<int, int>> v;

bool cmp(const pair<int,int> &p1,const pair<int,int> &p2) {
	if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
	}
	else if (p1.second < p2.second)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int input1, input2;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> input1 >> input2;
		v.push_back(make_pair(input1, input2));
	}

	sort(v.begin(), v.end(),cmp);

	int st = v[0].second;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (v[i].first < st)
			continue;
		cnt++;
		st = v[i].second;
	}
	cout << cnt;


	/*for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}*/
	
}
