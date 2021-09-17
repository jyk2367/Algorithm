#include <iostream>
#include <string>

using namespace std;

int arr[9];
bool visited[9];

int N, M;


void func(int k,int sp) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = sp; i <= N; i++) {
		if (!visited[i]) {
			arr[k] = i;
			visited[i] = true;
			func(k+1,i+1);
			visited[i] = false;
		}
	}


}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0,1);
}