#include <iostream>
#include <algorithm>

using namespace std;

int H, W, X, Y;
int B[602][602];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> H >> W >> X >> Y;
	
	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			B[i][j] -= B[i - X][j - Y];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}