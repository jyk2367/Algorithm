#include <iostream>
#include <algorithm>
#define MAX 1000003
using namespace std;

//로프
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int arr[MAX];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int sum = 0;
	for (int i = 1; i <=N; i++)
		sum = max(sum, arr[N - i] * i);
	cout << sum;
}