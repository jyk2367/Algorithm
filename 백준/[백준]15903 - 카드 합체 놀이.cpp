#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N,M;
priority_queue<long long,vector<long long>,greater<long long>> pq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}
	
	for (int i = 0; i < M; i++) {
		long long num1 = pq.top();
		pq.pop();
		long long num2 = pq.top();
		pq.pop();
		long long sum = num1 + num2;
		pq.push(sum);
		pq.push(sum);
	}

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum+= pq.top();
		pq.pop();
	}
	cout << sum << "\n";

	return 0;
}
