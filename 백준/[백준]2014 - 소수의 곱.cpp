#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int prime[101];
int K,N;
priority_queue<long long,vector<long long>,greater<long long>> pq;
unordered_map<long long,bool> hm;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> N;
	long long maxValue = 0;
	long long now = 0;

	for (int i = 0; i < K; i++) {
		cin >> prime[i];
		pq.push(prime[i]);
		maxValue = max((int)maxValue, prime[i]);
	}


	while (N-->0) {
		now=pq.top();
		pq.pop();
		
		for (int i = 0; i < K; i++) {
			long long next = prime[i] * now;

			if (next > maxValue&& pq.size() > N) {
				continue;
			}
			if (hm.count(next)==1)
				continue;
			
			hm[next] = 1;
			maxValue = max(maxValue, next);
			pq.push(next);

		}
	}
	
	cout << now<<"\n";

	return 0;
}
