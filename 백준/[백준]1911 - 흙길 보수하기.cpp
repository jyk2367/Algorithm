#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int N, L;
vector<pair<int,int>> pool;
int a, b;

bool comp(const pair<int,int> &p1,const pair<int,int> &p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		pool.push_back({ a, b });
	}

	sort(pool.begin(), pool.end(),comp);
	
	int ptr = 0;
	int cnt = 0;
	for(int i=0;i<N;i++){
		int st=pool[i].first;
		int ed=pool[i].second;

		if(ptr<st)
			ptr = st;

		int jumpCnt=(ed - ptr) / L;
		ptr += jumpCnt * L;
		cnt += jumpCnt;
		if(ptr < ed) {
			ptr += L;
			cnt++;
		}
	}

	cout << cnt << "\n";

	
	return 0;
}