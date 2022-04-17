#include <bits/stdc++.h>
using namespace std;

int N, M, H, m = 4;
bool ladder[31][11];

bool ch() {
	for (int i = 1; i <= N; i++) {
		int t = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][t])
				t++;
			else if (ladder[j][t - 1])
				t--;
		}
		if (t != i) 
			return false;
	}
	return true;
}
void dfs(int cn, int mc) {
	if (m != 4)return;
	if (mc == cn) {
		if (ch())
			m = m > cn ? cn : m;
		return;
	}
	for (int j = 1; j < N; j++) {
		for (int i = 1; i <= H; i++) {
			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j - 1])
				continue;
			ladder[i][j] = 1;
			dfs(cn + 1, mc);
			ladder[i][j] = 0;
			while (!(ladder[i][j - 1] || ladder[i][j + 1])) 
				i++;
		}
	}
}
int main() {
	cin >> N >> M >> H;
	for (int i = 0, x, y; i < M; i++) {
		cin >> x >> y;
		ladder[x][y] = 1;
	}
	for (int i = 0; i < 4; i++) {
		dfs(0, i);
		if (m != 4) {
			cout << m << "\n";
			break;
		}
	}
	if (m == 4)
		cout << -1 << "\n";

}