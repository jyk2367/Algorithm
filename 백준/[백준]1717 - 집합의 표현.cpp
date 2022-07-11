#include <iostream>
using namespace std;

int N, M;
int mtrx[1'000'000];

int find(int a) {
	if (mtrx[a] == a)
		return a;
	else
		return mtrx[a] = find(mtrx[a]);
}


void Union(int a,int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	//a집합으로 b집합을 넣음
	mtrx[bRoot] = aRoot;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		mtrx[i] = i;
	}
	while (M-->0) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) {
			Union(a, b);
		}
		else{
			int aSet = find(a);
			int bSet = find(b);
			if (aSet == bSet)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}