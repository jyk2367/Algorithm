#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int* A;
int* B;
int* C;
bool cmp(const int& a, const int& b) {
	return a >b;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N=0;
	cin >> N;

	A = new int[N];
	B = new int[N];
	C = new int[N];
	

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
 		cin >> B[i];
		C[i] = B[i];
	}
	sort(C, C+N,cmp);
	sort(A, A+N);
	


	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += C[i] * A[i];
	}


	cout << sum<<" ";

}