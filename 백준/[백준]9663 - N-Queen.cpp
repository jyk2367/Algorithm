#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
int **matrix;
int cnt;
bool **visited;

void func(int k) {
	if (k == N) {
		cnt++;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (!visited[k][i]) {

			queue<pair<int, int>> q;
			
			//대각선
			for (int j = k; j < N; j++) {
				if (visited[j][i] == false) {
					q.push(make_pair(j, i));
					visited[j][i] = true;
				}
				for (int p = 0; p < N; p++) {
					if (k + i == j + p|| k - i == j - p) {
						if (visited[j][p] == false) {
							q.push(make_pair(j, p));
							visited[j][p] = true;
						}
					}
				}
			}
			func(k + 1);
			while (!q.empty()) {
				pair<int,int> p=q.front();
				q.pop();
				visited[p.first][p.second] = false;
			}

		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	


	cin >> N;

	matrix = new int* [N];
	visited = new bool* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
		visited[i] = new bool[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	func(0);
	cout << cnt;
	
}