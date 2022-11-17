#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> al[200'002];
int val[200'002];
// dp[i][0] : i의 자식과 관계 없음
// dp[i][1] : i의 자식과 관계 있음
int dp[200'002][2];

void INPUT() {
	cin >> N;
	//사수 -> 부사수 list
	for (int i = 2; i <=N; i++) {
		int a;
		cin >> a;
		al[a].push_back(i);
	}

	//실력
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
	}
}

void dfs(int cur) {

	for (int next : al[cur]) {
		dfs(next);
		//자식과 관계가 없다면, 어떤 값이든 큰값만 오면 상관없음
		dp[cur][0] += max(dp[next][0], dp[next][1]);
	}
	
	int Sum = dp[cur][0];

	for (int next : al[cur]) {
		//부모와 관계가 있다면, 그 관계 제외값 + (현재-부모) 관계값
		dp[cur][1] = max(dp[cur][1], Sum - max(dp[next][0], dp[next][1]) + (val[cur] * val[next]) + dp[next][0]);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	INPUT();
	
	dfs(1);
	
	cout << max(dp[1][0],dp[1][1]) << "\n";

	return 0;

}