#include <iostream>
#include <string>

using namespace std;
int matrix[2000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		matrix[input + 1000000]++;
	}


	for (int i =0; i<= 2000001; i++) {
		while (matrix[i]--) {
			cout<<i- 1000000 <<"\n";
		}

	}
}