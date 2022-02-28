#include <bits/stdc++.h>
using namespace std;

int N, W, L;
queue<int> truck;
queue<pair<int, int>> bridge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> W >> L;
	
	int truckWeight;
	while (N--) {
		cin >> truckWeight;
		truck.push(truckWeight);
	}
	
	int time = 0, weight = 0;
	while (true) {
		time++;
		if (!bridge.empty()) {
			if (bridge.front().first == time) {
				weight -= bridge.front().second;
				bridge.pop();
			}
		}

		if (!truck.empty()) {
			if (weight + truck.front() <= L) {
				weight += truck.front();
				bridge.push({ time + W,truck.front() });
				truck.pop();
			}
		}
		if (truck.empty() && bridge.empty())
			break;
	}
	cout << time << "\n";


	return 0;
}