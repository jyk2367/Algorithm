#include <bits/stdc++.h>
#include <unordered_set>
#define PRIMESIZE 1'000'001
using namespace std;


bool prime[PRIMESIZE];

void makePrime() {
	for (int i = 2; i * i <= PRIMESIZE; i++) {
		if (prime[i])
			continue;
		for (int j = i+i; j <= PRIMESIZE; j += i) {
			prime[j] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string P;
	int K;
	cin >> P>>K;

	makePrime();
	int answer = 0x7fff'ffff;
	for (int i = 2; i <= K; i++) {
		if (prime[i])
			continue;
		int tmp = 0;
		for (int j = 0; j < P.length(); j++) {
			tmp = (tmp * 10 + P[j] - '0') % i;
		}
		if (tmp == 0) {
			answer = i;
			break;
		}
	}

	if (answer < K) {
		cout << "BAD "<<answer << "\n";
	}
	else {
		cout << "GOOD" << "\n";
	}


	return 0;
}
