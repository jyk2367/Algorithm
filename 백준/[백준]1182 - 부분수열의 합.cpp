#include <iostream>
#include <string>

using namespace std;
int N, S;
int arr[22];
bool visited[22];
int cnt;
void func(int k,int sum) {
	if (N == k) {
		if (sum == S)
			cnt++;
			return;
	}
	func(k + 1, sum);
	func(k+1,sum+arr[k]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	func(0,0);

	if (S == 0)
		cnt--;
	cout << cnt;
	
}