#include <iostream>

using namespace std;

int N, M;
int cntB, cntW;
int answer=65;
char mtrx[52][52];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			mtrx[i][j] = s[j];
		}
	}

	for (int a = 0; a < N - 7; a++) {
		for (int b = 0; b < M - 7; b++) {
			cntB = 0;
			cntW = 0;
			for (int i = a; i < a + 8; i++) {
				for (int j = b; j < b + 8; j++) {
					if ((i+j)%2==0) {
						if (mtrx[i][j] == 'B')
							cntW++;
						else
							cntB++;
					}
					else {
						if (mtrx[i][j] == 'B')
							cntB++;
						else
							cntW++;
					}
				}
			}
			answer = min(answer, min(cntB, cntW));
		}
	}

	cout << answer << "\n";


	return 0;
}