#include <bits/stdc++.h>

using namespace std;

struct FireBall {
	FireBall(int M, int S, int D) :
		m(M), s(S), d(D)
	{

	}
	int m;
	int s;
	int d;
};


int N, M,K;
vector<FireBall> FB[52][52];
vector<FireBall> tmp[52][52];


const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		FB[r][c].push_back(FireBall(m, s, d));
	}

	while (K--) {

		for (int i = 1; i <=N; i++) {
			for (int j = 1; j <= N; j++) {

				for (int p = 0; p < FB[i][j].size(); p++) {
					int nextR = i + dx[FB[i][j][p].d] * FB[i][j][p].s;
					int nextC = j + dy[FB[i][j][p].d] * FB[i][j][p].s;

					while(nextR <= 0) {
						nextR += N;
					}
					while(nextC <= 0) {
						nextC += N;
					}
					while(nextR > N) {
						nextR -= N;
					}
					while(nextC > N) {
						nextC -= N;
					}

					tmp[nextR][nextC].push_back(FB[i][j][p]);
				}
				FB[i][j].clear();
			}
		}
		

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tmp[i][j].size() == 1) {
					FB[i][j].push_back(tmp[i][j][0]);
					tmp[i][j].clear();
				}
				else if (tmp[i][j].size() >= 2) {
					const int FBcnt = tmp[i][j].size();

					int Msum = 0;
					int Ssum = 0;
					int oddCnt = 0;
					int evenCnt = 0;

					//같은 칸 파이어볼 하나로 합치기
					for (int p = 0; p < FBcnt; p++) {
						Msum += tmp[i][j][p].m;
						Ssum += tmp[i][j][p].s;
						if (tmp[i][j][p].d % 2 == 0)
							evenCnt++;
						else
							oddCnt++;
					}

					//4개로 나누기
					int newM = Msum / 5;
					int newS = Ssum / FBcnt;

					//질량 0이면 소멸
					if (newM == 0) {
						tmp[i][j].clear();
						continue;
					}

					if (evenCnt == FBcnt || oddCnt == FBcnt) {
						for (int p = 0; p < 4; p++) {
							FB[i][j].push_back(FireBall(newM, newS, p * 2));
						}
					}
					else {
						for (int p = 0; p < 4; p++) {
							FB[i][j].push_back(FireBall(newM, newS, p * 2 + 1));
						}
					}

					tmp[i][j].clear();

				}
			}
		}

	}
	
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			for (int p = 0; p < FB[i][j].size(); p++) {
				answer += FB[i][j][p].m;
			}

		}
	}
	cout << answer << "\n";

	return 0;
}