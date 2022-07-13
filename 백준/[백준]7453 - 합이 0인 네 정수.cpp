#include <iostream>
#include <algorithm>
#include <vector>
#define Pair pair<int,int>

using namespace std;

int A[4002], B[4002], C[4002], D[4002];
vector<int> AB,CD;
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	long long answer = 0;
	int ABSIZE = AB.size();
	for (int i = 0; i < ABSIZE; i++) {
		answer+=upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]);
	}

	cout << answer << "\n";



	return 0;
}
​