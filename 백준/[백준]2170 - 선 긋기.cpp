#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
pair<int, int> p[1'000'000];

bool comp(const pair<int,int>& p1,const pair<int,int>& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	
	sort(p, p + N,comp);

	int left = 0x8000'0000;
	int right = 0x8000'0000;
	int length = 0;
	for (int i = 0; i < N; i++) {
		if (p[i].first<=right) {
			right = max(right, p[i].second);
		}
		else {
			length += right - left;
			left = p[i].first;
			right = p[i].second;
		}
	}
	length += right - left;

	cout << length << "\n";

	return 0;
}
