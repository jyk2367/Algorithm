#include <bits/stdc++.h>
using namespace std;


bool func(int x,const int &sp,bool visited[1002],vector<int> v[1002]) {
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] == sp)
			return true;
		else
			return func(v[x][i], sp, visited,v);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> v[1002];

		for (int i = 1; i <= N; i++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}

		bool visited[1002];
		for (int i =1 ; i <= N; i++) {
			visited[i] = false;
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]&&func(i, i, visited,v)) {
				cnt++;
			}
		}

		cout << cnt << "\n";

	}
	

	return 0;
}
​