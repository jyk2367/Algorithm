#include <iostream>
#include <string>

using namespace std;

int arr[9];
int N, M;
bool visited[9];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[k] = i;
			visited[i] = 1;
			func(k + 1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0);

}