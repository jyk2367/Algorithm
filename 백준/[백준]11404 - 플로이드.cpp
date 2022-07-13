#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int a, b, c;
int am[101][101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j)
				am[i][j] = INF;
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;
		am[a][b] = min(am[a][b],c);  
	}
	
	for (int k = 1; k <= N; k++) {			//경유지
		for (int i = 1; i <= N; i++) {		//출발지
			for (int j = 1; j <= N; j++) {	//도착지
				if (am[i][j] > am[i][k] + am[k][j])
					am[i][j] = am[i][k] + am[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (am[i][j] == INF) {
				cout << 0 << " ";
			}
			else
				cout << am[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}