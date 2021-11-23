#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	int A[100000];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	int lowb=0x7fffffff;
	int sp=0,ep=0;

	sort(A, A + N);
	for (int sp = 0; sp < N; sp++) {
		while (ep < N&&A[ep] - A[sp] < M)
			ep++;
		if (ep == N)
			break;
		lowb = min(lowb, A[ep] - A[sp]);
	}
	
	cout << lowb;

	return 0;
}


/*
	sort(A, A + N);
	for (int i = 0; i < N; i++) {
		if (A[i] + M <= A[N - 1]) {
			lowb=min(lowb,*lower_bound(A, A + N, A[i] + M)-A[i]);
		}
	}//O(nlogn)
*/