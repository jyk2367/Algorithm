#include <bits/stdc++.h>
using namespace std;

int A, B;
bool primeCheck(int num);
void setAB(int num);

void setAB(int num) {
	for (int i = 2; i <=num/2; i++) {
		if (primeCheck(i) && primeCheck(num - i)) {
			A = i;
			B = num - i;
			return;
		}
	}
}

bool primeCheck(int num) {
	if (num < 2)
		return false;
	else if (num == 2)
		return true;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	while (true) {
		int num;
		cin >> num;
		
		if (num == 0)
			break;
		setAB(num);
		if (A==0&&B==0)
			cout << "Goldbach's conjecture is wrong." << "\n";
		else
			cout << num << " = " << A << " + " << B << "\n";
	}



	return 0;
}