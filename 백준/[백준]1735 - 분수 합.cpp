#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int A, B,C,D;

int gcd(int x,int y) {

	int tmp = 0;
	while (y!=0) {
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

	cin >> A >> B >> C >> D;

	int E = A * D + B * C;
	int F = B * D;

	int gcdef = gcd(E, F);
	cout << E / gcdef <<" " << F / gcdef << "\n";
	

	return 0;
}
