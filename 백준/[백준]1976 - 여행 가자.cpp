#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool adj_matrix[202][202];

int parent[202];

int Find(int i) {
	if (parent[i] == i) {
		return i;
	}

	return parent[i] = Find(parent[i]);
}

void Union(int i,int j) {
	if (parent[i] == parent[j])
		return;
	int iRoot = Find(i);
	int jRoot = Find(j);
	parent[jRoot] = iRoot;
}


void Init() {
	for (int i = 1; i <=N; i++) {
		parent[i] = i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	Init();

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			cin >> adj_matrix[i][j];
			if (adj_matrix[i][j]&& i < j) {
				Union(i, j);
			}
		}
	}

	bool state=true;
	int now;
	int input;
	cin >> input;
	now = Find(input);
	for (int i = 0; i < M-1; i++) {
		cin >> input;
		if (now != Find(input)) {
			state = false;
			break;
		}
	}

	if (state) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}