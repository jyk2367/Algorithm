#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[100002];
bool visited[100002];
int answer;
int rp;

void dfs(int sp,int sum) {
	visited[sp] = true;
	if (answer < sum) {
		rp = sp;
		answer = sum;
	}

	int VSIZE = v[sp].size();
	for (int i = 0; i < VSIZE; i++) {
		pair<int, int> p = v[sp][i];
		int next=p.first;
		int weight = p.second;
		if (!visited[next]) {
			dfs(next,sum+weight);
		}
	}
	visited[sp] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V;
	cin >> V;
	int vtmp = V;
	while (vtmp--) {
		int n1, n2, w;
		cin >> n1;
		while (true) {
			cin >> n2;
			if (n2 == -1)
				break;
			cin >> w;

			v[n1].push_back({ n2,w });
		}
	}

	dfs(1,0);
	dfs(rp,0);

	cout << answer << "\n";
	
	return 0;
}