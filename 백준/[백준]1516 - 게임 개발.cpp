#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
struct Building {
	int indegree;
	int time;
	int cost;
	vector<int> precedence;
};
Building building[100'001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 1; i <=N; i++) {
		cin >> building[i].cost;
		while (true) {
			int input;
			cin >> input;
			if (input == -1)
				break;
			//input과 i가 연결됨 input -> i
			building[i].indegree++;
			building[input].precedence.push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (building[i].indegree == 0) {
			q.push(i);
			building[i].time = building[i].cost;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		vector<int>& precedence = building[now].precedence;
		int PSIZE = precedence.size();
		for (int i = 0; i < PSIZE; i++) {
			int nx=precedence[i];
			building[nx].indegree--;
			building[nx].time = max(building[nx].cost + building[now].time, building[nx].time);
			if (building[nx].indegree == 0) {
				q.push(nx);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << building[i].time << "\n";
	}
	
	return 0;
}