#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

struct Ticket {
	int Arrival;
	int Cost;
	int Time;

	Ticket(int v,int c,int t):Arrival(v),Cost(c),Time(t) {	}
};

struct t_comp {
	bool operator()(const Ticket& t1, const Ticket& t2) {
		if (t1.Time == t2.Time) {
					return t1.Cost > t2.Cost;
		}
		return t1.Time > t2.Time;
	}
};


int T, N, M, K;
int u, v, c, d;

priority_queue<Ticket, vector<Ticket>, t_comp> pq;
vector<Ticket> airport[102];
int t[102][10002];


void Init() {
	for (int i = 0; i < 102; i++) {
		airport[i].clear();
		for(int j = 0; j <= 10000; j++) {
			t[i][j] = INF;
		}
	}
	while (!pq.empty()) {
		pq.pop();
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		Init();
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;
			//u에서 출발, v로 가면서 비용은 c, 소요시간은 d
			airport[u].push_back(Ticket(v,c, d));
		}

		pq.push(Ticket(1, 0, 0));
		t[1][0] = 0;

		while (!pq.empty()) {
			int now = pq.top().Arrival;
			int nowCost = pq.top().Cost;
			int nowTime = pq.top().Time;
			pq.pop();
			if (t[now][nowCost] < nowTime)
				continue;
			if (nowCost > M)
				continue;
			if (now == N)
				break;

			for (Ticket ticket : airport[now]) {
				int next = ticket.Arrival;
				int nextCost = nowCost + ticket.Cost;
				int nextTime = nowTime + ticket.Time;

				if (nextCost <= M && nextTime < t[next][nextCost]) {
					for (int j = nextCost; j <= M; j++) {
						if (t[next][j] > nextTime) {
							t[next][j] = nextTime;
						}
					}
					pq.push(Ticket(next, nextCost, nextTime));
				}
			}
		}


		int answer = 0x7fff'ffff;
		for (int i = 1; i <=M; i++) {
			answer = min(answer, t[N][i]);
		}
		
		if(answer ==INF)
			cout << "Poor KCM" << "\n";
		else
			cout << answer << "\n";

	}
	

	return 0;
}