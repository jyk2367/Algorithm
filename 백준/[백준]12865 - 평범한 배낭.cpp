#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define weight first
#define value second
using namespace std;


int N, K;
vector<pair<int, int>> v;
int result[102][100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N >> K;
	int W, V;
	
	for (int i = 0; i < N; i++) {
		cin >> W>>V;
		v.push_back(make_pair(W, V));
	}

	
	for (int i = 1; i <=N; i++) {
		for (int j =1; j <=K; j++) {
			if (j >= v[i-1].weight)
				result[i][j] = max(result[i - 1][j], v[i-1].value + result[i - 1][j - v[i-1].weight]);
			else {
				result[i][j] = result[i - 1][j];
			}
		}
	}

	cout << result[N][K];
	
}