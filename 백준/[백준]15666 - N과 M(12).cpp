#include <bits/stdc++.h>


using namespace std;

int N, M;

void func(int k,int idx,vector<int> &v,vector<int> &answer) {
	if (k >= M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	int before = -1;
	for (int i = idx; i < N; i++) {
		if (before!=v[i]) {
			before = v[i];
			answer[k] = v[i];
			func(k+1,i, v, answer);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int> v,answer(11);
	
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	//void func(int k,int idx,int last,vector<int> &v,vector<int> &answer) 
	func(0,0,v, answer);


	return 0;
}