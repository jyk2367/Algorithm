#include <bits/stdc++.h>
using namespace std;

int r, c;
int answer;
void recv(int row,int col, int N) {
	if (N==1) {
		return;
	}

	if (row + N / 2 > r && col + N / 2 > c) {
		recv(row, col, N / 2);
	}
	else if (row + N / 2 > r && col + N / 2 <= c) {
		answer += (N / 2) * (N / 2);
		recv(row, col + N / 2, N / 2);
	}
	else if (row + N / 2 <= r && col + N / 2 > c) {
		answer += (N / 2) * (N / 2) * 2;
		recv(row + N / 2, col, N / 2);
	}
	if (row + N / 2 <= r && col + N / 2 <=c) {
		answer+= (N / 2) * (N / 2) * 3;
		recv(row + N / 2, col + N / 2, N / 2);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N;
	cin >> N>>r>>c;
	
	N= pow(2, N);

	recv(0,0,N);

	cout << answer<<"\n";
	
	return 0;
}