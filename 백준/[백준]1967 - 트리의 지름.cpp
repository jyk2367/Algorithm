#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[10002];
bool visited[10002];
int rp;
int answer;

void dfs(int sp,int sum) {
	int result = sum;
	visited[sp] = true;	

	if (sum > answer) {
		answer = sum;
		rp = sp;
	}

	int VSIZE = v[sp].size();
	for (int i = 0; i < VSIZE; i++) {
		pair<int, int> p = v[sp][i];
		int next = p.first;
		int weight = p.second;
		if (!visited[next]) {
			dfs(next, sum + weight);
		}
	}
	visited[sp] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int num = N - 1;
	while (num--) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		v[n1].push_back({ n2,w });
		v[n2].push_back({ n1,w });
	}

	dfs(1, 0);
	dfs(rp, 0);

	cout << answer << "\n";
	
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int,int>> v[10002];
// bool visited[10002];

// int dfs(int sp,int sum) {
// 	int result = sum;
// 	int VSIZE = v[sp].size();
// 	for (int i = 0; i < VSIZE; i++) {
// 		pair<int, int> p = v[sp][i];
// 		int next = p.first;
// 		int weight = p.second;
// 		if (!visited[next]) {
// 			visited[next] = true;
// 			result=max(dfs(next, sum + weight),result);
// 			visited[next] = false;
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	int N;
// 	cin >> N;
// 	int num = N - 1;
// 	while (num--) {
// 		int n1, n2, w;
// 		cin >> n1 >> n2 >> w;
// 		v[n1].push_back({ n2,w });
// 		v[n2].push_back({ n1,w });
// 	}

// 	int answer = 0;
// 	for (int i = 1; i <= N; i++) {
// 		visited[i] = true;
// 		answer=max(dfs(i,0),answer);
// 		visited[i] = false;
// 	}

// 	cout << answer << "\n";
	
// 	return 0;
// }