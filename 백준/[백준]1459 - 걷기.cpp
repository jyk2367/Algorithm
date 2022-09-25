#include <iostream>
#include <algorithm>

using namespace std;

// 한블록 W, 대각 S
long long X, Y, W, S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> X >> Y >> W >> S;
	
	//대각선 하나보다 한블록 두개가 더 나은경우
	if (S > W * 2) {
		cout << X * W + Y * W << "\n";
	}
	// ㅡㅡ 보다 /\가 나으면
	else if(2 * W > 2 * S){
		//짝수위치라면 
		if ((X + Y) % 2 == 0)
			cout << max(X, Y) * S << "\n";
		else
			cout << (max(X, Y) - 1) * S + W << "\n";
	}
	//대각선이 더 나은경우
	else {
		cout << min(X, Y) * S + (max(X, Y) - min(X, Y)) * W << "\n";
	}

	return 0;
}