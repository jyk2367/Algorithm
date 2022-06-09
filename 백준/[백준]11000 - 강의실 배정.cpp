#include <bits/stdc++.h>

using namespace std;



int N;
pair<int, int> p[200001];
priority_queue<int, vector<int>, greater<int> > pq;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int time=0x7fffffff;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first>>p[i].second;
	}
	
	sort(p, p + N);

	pq.push(p[0].second);
	for (int i = 1; i < N; i++) {
		pq.push(p[i].second);
		if (pq.top() <= p[i].first) {
			pq.pop();
		}
	}

	cout << pq.size()<<"\n";


	return 0;
}