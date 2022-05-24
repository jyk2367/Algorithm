#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> space[102];
int M, N;
int cnt = 0;
bool samePlanet(int a,int b) {
	for (int i = 0; i < N; i++) {
		if (space[a][i].second != space[b][i].second) {
			return false;
		}
		else {
			if (i != N - 1) {
				if ((space[a][i].first < space[a][i + 1].first) != (space[b][i].first < space[b][i + 1].first)) {
					return false;
				}
			}
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			space[i].push_back({ input,j });
		}
		sort(space[i].begin(), space[i].end());
	}

	for (int i = 0; i < M-1; i++) {
		for (int j = i+1; j < M; j++) {
			if (samePlanet(i, j) == true) {
				cnt++;
			}
		}

	}

	cout << cnt;

	return 0;
}
