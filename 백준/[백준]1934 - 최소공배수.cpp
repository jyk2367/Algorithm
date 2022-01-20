#include <bits/stdc++.h>
using namespace std;

int getGCD(int x, int y) {
	int num=0;
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

int getLCM(int x, int y) {
	return (x * y)/ getGCD(x, y);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T,num1,num2;
	cin >> T;
	while (T--) {
		cin >> num1 >> num2;
		cout<<getLCM(num1, num2)<<"\n";
	}
	
	return 0;
}