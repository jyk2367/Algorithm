#include <iostream>

#define INF 0x3f3f3f3f
using namespace std;

bool am[502][502];
int N, M;
int a, b;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j)
				am[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		am[a][b] = 1;
	}
	

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (am[i][k] == 1 && am[k][j] == 1)
					am[i][j] = 1;
			}
		}
	}
	
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (am[i][j] == 1 || am[j][i] == 1)
				cnt++;
		}
		if (cnt == N - 1)
			answer++;
	}
	cout << answer << "\n";

	return 0;
}