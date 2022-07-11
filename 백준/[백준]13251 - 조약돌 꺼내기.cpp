#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int M, K;
int SCBC[52];//StoneCntByColor

double func(int N, int k) {
	if (N - k < k) {
		k = N - k;
	}

	double top = 1;
	double bottom = 1;
	for (int i = 0; i < k; i++) {
		top *= N;
		N--;
	}
	for (int i = 1; i <=k; i++) {
		bottom *= i;
	}
	return top / bottom;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> SCBC[i];
	}
	cin >> K;

	int N = 0;
	double a = 0;
	for (int i = 0; i < M; i++) {
		N += SCBC[i];
		if (SCBC[i] >=K) {
			a += func(SCBC[i], K);
		}
	}
	double b=func(N, K);

	cout << fixed;
	cout.precision(15);
	cout << a / b << "\n";

	return 0;
}
