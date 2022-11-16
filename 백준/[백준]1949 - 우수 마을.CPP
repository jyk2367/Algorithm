#include <iostream>
#include <vector>
using namespace std;

vector<int> al[10002];
int pp[10002];
int dp[10002][2];
bool visited[10002];
int N;

void dfs(int cur) {
	if (visited[cur])
		return;

	visited[cur] = true;
	dp[cur][0] = 0;
	dp[cur][1] = pp[cur];

	for (int next : al[cur]) {
		if (visited[next]) 
			continue;
		dfs(next);

		//X : O,X 
		dp[cur][0] = dp[cur][0] + max(dp[next][0], dp[next][1]);
		//O : X
		dp[cur][1] = dp[cur][1] + dp[next][0];
	}

}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pp[i];
	}
	
	for (int i = 1; i <N; i++) {
		int a, b;
		cin >> a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Input();
	
	dfs(1);

	cout << max(dp[1][0], dp[1][1])<<"\n";
	
	return 0;

}