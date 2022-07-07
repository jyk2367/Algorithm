#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int t;
long long K, C;

int gcd(int x, int y) {
	int tmp = x;
	while (y) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t-- > 0) {
		cin >> K >> C;

		if (K == 1 && C == 1) { //사람수 1, 1봉지 -> 사탕 2개 필요하므로 2봉지 
			cout << 2 << "\n";
			continue;
		}
		else if (K == 1) { // 사람수 1 -> C는 1보단 큰 수이고, 사탕은 2개이므로 1봉지면 충분
			cout << 1 << "\n";
			continue;
		}
		else if (C == 1) { // 1봉지 1사탕이므로 사람수가 1e9명보다 많은 경우만 처리
			if (K + 1 > 1e9)
				cout << "IMPOSSIBLE" << "\n";
			else
				cout << K + 1 << "\n";
			continue;
		}

		else if (gcd(K,C)!=1) { //사람수와 사탕개수가 서로소가 아니라면 +1개만큼 차이날수밖에 없음
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}


		int r1 = K, r2 =C;
		int s1 = 1, s2 = 0;
		int t1 = 0, t2 = 1;
		int r, s, t, q;

		while (r2 != 0) {
			q = r1 / r2;
			//gcd 계산
			r = r1 % r2;
			r1 = r2;
			r2 = r;

			//s 계산
			s = s1 - q * s2;
			s1 = s2;
			s2 = s;

			//t 계산
			t = t1 - q * t2;
			t1 = t2;
			t2 = t;

		}
		r = r1;
		s = s1;
		t = t1;

		while (t < 0)
			t += K;

		if(t>1e9)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << t << "\n";
	}

	return 0;
}