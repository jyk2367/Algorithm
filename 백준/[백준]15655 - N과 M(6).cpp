#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;

int *number;
int arr[10];
bool visited[10];

void func(int k,int start) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= N; i++) {
		if (!visited[i]) {
			arr[k] = number[i];
			visited[i] = true;
			func(k + 1, i);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;


	int num;
	number = new int[10];
	for (int i = 1; i <=N; i++) {
		cin >> num;
		number[i]=num;
	}
	sort(number+1, number + N+1);
	
	func(0,1);

}