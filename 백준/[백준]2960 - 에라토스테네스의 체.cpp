#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int N,K;
bool mtrx[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	mtrx[0] = true,mtrx[1]=true;
	int p=2;
	int idx = 1;
	while (true) {
		//아직 지우지 않은 수중 가장 작은 수 P 찾기 + P는 소수
		for (; p <= N; p++) {
			if (mtrx[p] == false)
				break;
		}

		if (p > 1000)
			break;

		//P를 지우고 아직 지우지 않은 P의 배수를 크기 순서대로 지움
		for (int i = p; i <=N; i+=p) {
			if (!mtrx[i]) {
				mtrx[i] = true;
				if (idx == K) {
					cout << i << "\n";
				}
				idx++;
			}
		}

		if (idx>K)
			break;
		
	}

	return 0;
}
