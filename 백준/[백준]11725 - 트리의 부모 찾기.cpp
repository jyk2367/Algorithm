#include <bits/stdc++.h>
using namespace std;

vector<int> v[100002];
int parent[100002];

void func(int x) {
	stack<pair<int,vector<int>>> st;
	st.push({ x,v[x] });
	 
	while (!st.empty()) {
		pair<int,vector<int>> now = st.top();
		st.pop();
		
		int nowSIZE = now.second.size();

		for (int i = 0; i < nowSIZE; i++) {
			int next = now.second[i];
			if (parent[next] != 0)
				continue;
			st.push({now.second[i],v[now.second[i]] });
			parent[next] = now.first;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N;
	cin >> N;
	int num = N-1;
	while (num--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	func(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}