#include <iostream>
#include <string>

using namespace std;

int arr[9];
bool visited[9];

int N, M;


void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[k] = i;
		func(k+1);
	}


}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0);
}