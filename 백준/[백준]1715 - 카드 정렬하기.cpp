#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	priority_queue<int,vector<int>,greater<int>> pq;
	
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int answer = 0;
	while (pq.size() > 1) {
		int n1=pq.top();
		pq.pop();
		int n2=pq.top();
		pq.pop();
		answer += n1 + n2;
		pq.push(n1 + n2);
	}

	cout << answer;

	return 0;
}