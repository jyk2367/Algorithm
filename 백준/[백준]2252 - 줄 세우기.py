#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
struct Student {
	int indegree;
	int outdegree;
	
	vector<int> v;
};

Student s[32'001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		s[a].outdegree++;
		s[a].v.push_back(b);
		s[b].indegree++;
		s[b].v.push_back(a);
	}

	queue<int> q;
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		if (s[i].indegree == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		answer.push_back(now);
		
		vector<int>& connected = s[now].v;
		int CSIZE = connected.size();
		for (int i = 0; i < CSIZE; i++) {
			int nx = connected[i];
			s[nx].indegree--;
			if (s[nx].indegree == 0)
				q.push(nx);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}