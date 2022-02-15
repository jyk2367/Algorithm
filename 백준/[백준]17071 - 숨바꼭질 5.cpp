#include <bits/stdc++.h>
using namespace std;

int N,K;
int visited[500001][2];//0 : 짝수초일 때 방문?, 1 : 홀수초일 때 방문?
struct comp {
	bool operator()(const pair<int, int>& p1,const pair<int, int>& p2) {
		return p1.second > p2.second;//최솟값 맨위
	}
};

int func() {

	//현재 위치,시간
	priority_queue<pair<int, int>,vector<pair<int, int>>,comp> pq;
	pq.push({N,0});
	visited[N][0] = 0;
	

	while (!pq.empty()) {
		int nowN = pq.top().first;
		int nowT = pq.top().second;
		pq.pop();
		int nowK = K+(nowT+1)*nowT/2;
		if (nowK > 500000)
			return -1;
		
		if (nowK == nowN||visited[nowK][nowT%2]) {
			return nowT;
		}


		int nextN1 = nowN - 1;//nowMoveDir : 0
		int nextN2 = nowN + 1;//nowMoveDir : 1
		int nextN3 = nowN * 2;//nowMoveDir : 2

		if (0 <= nextN1 && nextN1 <= 500000&& !visited[nextN1][(nowT+1)% 2]) {
			pq.push({ nextN1,nowT + 1 });
			visited[nextN1][(nowT + 1) % 2] = true;
		}
		if (0 <= nextN2 && nextN2 <= 500000&& !visited[nextN2][(nowT + 1) % 2]) {
			pq.push({ nextN2,nowT + 1 });
			visited[nextN2][(nowT + 1) % 2] = true;
		}
		if (0 <= nextN3 && nextN3 <= 500000&& !visited[nextN3][(nowT + 1) % 2]) {
			pq.push({nextN3 ,nowT + 1});
			visited[nextN3][(nowT + 1) % 2] = true;
		}
	}
	

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	
	cout<<func();

	return 0;
}