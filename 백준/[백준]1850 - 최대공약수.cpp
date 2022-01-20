#include <bits/stdc++.h>
using namespace std;

long long getGCD(long long x, long long y) {
	long long num=0;
	while (y!=0) {
		num =x%y;
		x=y;
		y=num;
	}
	/*int num = min(x,y);
	while (num>1) {
		if (x % num == 0 && y % num == 0)
			return num;
		num--;
	}*/
	return x;
}

long long getLCM(long long x, long long y) {
	return (x * y)/ getGCD(x, y);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long num1, num2;
	cin >> num1 >> num2;
	long long N = getGCD(num1, num2);
	string s = "";
	while (N-->0) {
		s += "1";
	}

	cout << s << "\n";
	
	return 0;
}