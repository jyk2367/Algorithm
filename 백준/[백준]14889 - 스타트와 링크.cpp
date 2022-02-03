#include <bits/stdc++.h>

using namespace std;

int matrix[22][22];
bool visited[22];
int N;
int answer=0x7fffffff;

void func(int idx,int k) {
	if (k == N/2) {
		vector<int> start;
		vector<int> link;
		int start_sum = 0;
		int link_sum = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i])
				start.push_back(i);
			else
				link.push_back(i);

		}
		for (int i = 0; i < N/2-1; i++) {
			for (int j = i+1; j < N/2; j++) {
				start_sum += matrix[start[i]][start[j]] + matrix[start[j]][start[i]];
				link_sum += matrix[link[i]][link[j]] + matrix[link[j]][link[i]];
			}
		}
		
		answer = min(abs(start_sum-link_sum), answer);

		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(i,k+1);
			visited[i] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	func(0,0);

	cout << answer << "\n";
	
	return 0;
}