#include <bits/stdc++.h>

using namespace std;
int N;
int s[10], w[10];
int cnt = 0;

void func(int k, vector<pair<int, int>> &v) {
	if (k == N) {
		int S[10], W[10];
		for (int i = 0; i < N; i++) {
			S[i] = s[i];
			W[i] = w[i];
		}
		for (int i = 0; i < N; i++) {
			// first번째 달걀을 second번째 달걀과 부딛히기
			if (S[v[i].first] <=0 || S[v[i].second] <= 0)
				continue;
			S[v[i].first] -= W[v[i].second];
			S[v[i].second] -= W[v[i].first];
		}
		int eggcnt = 0;
		for (int i = 0; i <N; i++) {
			if (S[v[i].first] <= 0)
				eggcnt++;
		}
		cnt = max(cnt, eggcnt);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (i != k) {
			v.push_back({k,i});
			func(k + 1, v);
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s[i]>>w[i];
	}
	vector<pair<int, int>> v;
	func(0,v);
	cout << cnt << "\n";

	return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// int N;
// int s[10], w[10];
// int cnt = 0;

// void func(int k) {
// 	if (k == N) {
// 		int eggcnt = 0;
// 		for (int i = 0; i < N; i++) {
// 			if (s[i] <= 0)
// 				eggcnt++;
// 		}
// 		cnt = max(cnt, eggcnt);
// 		return;
// 	}

// 	if (s[k] <= 0)
// 		func(k + 1);
// 	else {
// 		bool flag = false;
// 		for (int i = 0; i < N; i++) {
// 			if (i == k || s[i] <= 0)
// 				continue;
// 			s[k] -= w[i];
// 			s[i] -= w[k];
// 			flag = true;
// 			func(k + 1);
// 			s[k] += w[i];
// 			s[i] += w[k];
// 		}
// 		if (!flag)
// 			func(N);
// 	}
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	cin >> N;

// 	for (int i = 0; i < N; i++) {
// 		cin >> s[i] >> w[i];
// 	}
// 	func(0);
// 	cout << cnt << "\n";

// 	return 0;
// }
