#include <bits/stdc++.h>
#include <unordered_set>
#define PRIMESIZE 1'000'001

using namespace std;

bool prime[PRIMESIZE];

void makePrime() {
	for (int i = 2; i * i <=PRIMESIZE; i++) {
		if (prime[i])
			continue;
		for (int j = i + i; j <= PRIMESIZE; j += i) {
			prime[j] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	makePrime();
	int input;
	while (true) {
		cin >> input;
		if (input == 0)
			break;

		int a=0, b=0;
		for (int j = input-2; j >= 2; j--) {
			if (prime[j]==false && prime[input-j]==false) {
				b = j;
				a = input - j;
				break;
			}
		}
		if (a != 0 && b != 0)
			cout << input << " = " << a << " + " << b << "\n";
		else
			cout << "Goldbach's conjecture is wrong." << "\n";
	}

	
	return 0;
}
