#include <iostream>
#include <vector>

#define CITYSIZE 502
#define EDGESIZE 6002
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int A, B, C;

long long dist[CITYSIZE];
struct E_T {
	int a, b, c;
}E[EDGESIZE];

bool bellmanFord(int start) {
	dist[start] = 0;
	bool cycle = false;
	for (int i = 1; i <= N-1; i++) {
		for (int j = 0; j < M; j++) {
			int now = E[j].a;
			int next = E[j].b;
			int time = E[j].c;
			if (dist[now] < INF && dist[now] + time < dist[next]) {
				dist[next] = dist[now] + time;
			}
		}
	}

	//음수 사이클용 1번 더 돌리기
	for (int j = 0; j < M; j++) {
		int now = E[j].a;
		int next = E[j].b;
		int time = E[j].c;
		if (dist[now] < INF && dist[now] + time < dist[next]) {
			cycle = true;
			break;
		}
	}

	return cycle;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i <M; i++) {
		cin >> E[i].a >> E[i].b >> E[i].c;
	}
	
	if (bellmanFord(1))
		cout << -1 << "\n";
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}
		
	

	return 0;
}