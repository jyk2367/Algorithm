#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string,int> hm;

int K, L;

bool comp(const pair<string, int>& p1, const pair<string, int>& p2) {
	return p1.second < p2.second;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K>>L;
	int cnt = 0;
	for (int i = 0; i < L; i++) {
		string input;
		cin >> input;
		hm[input]=i;
	}

	vector<pair<string, int>> v;
	for (auto &p : hm) {
		v.push_back(p);
	}
	
	sort(v.begin(), v.end(),comp);
	for (int i = 0; i < min(K, (int)v.size()); i++) {
		cout << v[i].first << "\n";
	}

	return 0;
}
