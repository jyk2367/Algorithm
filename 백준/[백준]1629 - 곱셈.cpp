#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int func(int A, int B, int C) {
	if (B == 1) {
		return A%C;
	}
	long long num=func(A, B / 2, C)%C;
	
	if (B % 2 == 0)
		return (num * num)%C;
	else
		return ((num * num)%C * A)%C;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	cout<<func(A, B, C);



}